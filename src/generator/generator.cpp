#include "generator.h"
#include <fstream>

void Generator::Save(std::string path) {
    std::ofstream output_stream(path);
    this->module->print(output_stream, nullptr);
}

Generator::Generator():builder(context), data_layout(&context){
    this->module = std::make_unique<llvm::Module>("pascal_module", context);
}

Generator::~Generator() {
    for (auto blk: block_stack) delete blk;
    delete module;
}