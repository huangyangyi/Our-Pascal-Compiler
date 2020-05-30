#include "generator.h"
#include <fstream>

void Generator::Save(std::string path) {
    int fd = open(path.c_str(), O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        std::cerr << "cannot generate output file " << filename << ", errno: " << errno << std::endl;
        return false;
    }
    if (dup2(fd, 1) < 0) {
        std::cerr << "cannot dup output file to stdout, errno: " << errno << std::endl;
        return false;
    }
    close(fd);
    this->module->print(output_stream(llvm::outs(), nullptr);
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