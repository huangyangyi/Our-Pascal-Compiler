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