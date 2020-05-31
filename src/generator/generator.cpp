#include "generator.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>
#include <sys/stat.h>
#include <fstream>
#include <llvm/Support/Error.h>
#include "type/type.h"
#include <assert.h>

void Generator::Save(std::string path) {
    int fd = open(path.c_str(), O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        std::cerr << "cannot generate output file " << path << ", errno: " << errno << std::endl;
    }
    if (dup2(fd, 1) < 0) {
        std::cerr << "cannot dup output file to stdout, errno: " << errno << std::endl;
    }
    close(fd);
    this->module->print(llvm::outs(), nullptr);
}

Generator::Generator():builder(this->context) {
    this->module = std::make_unique<llvm::Module>("pascal_module", this->context);
    error_message.clear();
    error_position.clear();
}

std::shared_ptr<VisitorResult> Generator::RecordErrorMessage(std::string cur_error_message, std::pair<int, int> location){
    error_message.push_back(cur_error_message);
    error_position.push_back(location);
    return nullptr;
}

bool Generator::hasError(){return error_message.size() > 0;}
void Generator::printError(){
    for (int i = 0; i < error_message.size(); i++){
        std::string location = "[Error]  ";
        if (error_position[i] != std::make_pair(-1, -1))
            location = "[Error in (" + std::to_string(error_position[i].first) + ", " + std::to_string(error_position[i].second) + ")]  ";
        std::cout << location + error_message[i] << std::endl;
    }
}

Generator::~Generator() {
    for (auto blk: this->block_stack) {
        delete blk;
    }
    delete this->module.release();
}
CodeBlock* Generator::getCurrentBlock(void) { return *(this->block_stack.rbegin()); }

std::pair<std::vector<std::string>, std::vector<OurType::PascalType *> > Generator::getAllLocalVarNameType() {
    std::vector<std::string> name_list;
    std::vector<OurType::PascalType *> type_list;

    if (this->block_stack.size() == 1)
        return make_pair(name_list, type_list);

    for(auto it : this->getCurrentBlock()->named_values) {
        std::string name = it.first;
        OurType::PascalType *type = nullptr;
        for(int i = this->block_stack.size()-1; i >= 1; i--) {
            // do not count global variable
            // use the nearest one as it is the currently using type
            if (this->block_stack[i]->isType(name, true)) {
                type = this->block_stack[i]->named_types[name];
                break;
            }
        }

        assert(type != nullptr);

        name_list.push_back(name);
        type_list.push_back(type);
    }
    return std::make_pair(name_list, type_list);
}

OurType::PascalType *Generator::getVarType(std::string id) {
    if (!this->getCurrentBlock()->isValue(id) && !this->block_stack[0]->isValue(id)) {
        std::cout << "variable not found, return nullptr" << std::endl;
        return nullptr;
    }
    for(int i = this->block_stack.size()-1; i >= 0; i--) {
        if (this->block_stack[i]->isType(id, true)) {
            return this->block_stack[i]->named_types[id];
        }
    }
    return nullptr;
}