#include "generator.h"
#include <llvm/Type.h>

llvm::Value* GenSysWrite(const std::vector<std::shared_ptr<ValueResult>> &args_list, bool new_line, llvm::Context &context, llvm::IRBuilder &builder, llvm::Module &module) {
    static llvm::Function *llvm_printf = nullptr;
    if (llvm_printf == nullptr) {
        //register printf
        std::vector<llvm::Type *> arg_types = {llvm::Type::getInt8PtrTy(context)};
        llvm::FunctionType *func_type = llvm::FunctionType::get(
            llvm::Type::getInt32Ty(),
            arg_types,
            true
        );
        llvm::Function *func = llvm::Function::Create(
            func_type,
            llvm::Function::ExternalLinkage,
            "printf",
            &module
        );
        func->setCallingConv(llvm::CallingConv::C);
        llvm_printf = func;
    }
    std::string format;
    std::vector<Value *> printf_args;
    printf_args.emplace_back(nullptr);
    for (auto arg: args_list) {
        OurType::PascalType *tp = arg->getType();
        if (tp->isIntegerTy()) {
            format += "%d";
            printf_args.emplace_back(arg->getValue());
        }
        else if (tp->isFloatingPointTy()) {
            format += "%lf";
            printf_args.emplace_back(arg->getValue());
        }
        else if (tp->isCharTy()) {
            format += "%c";
            printf_args.emplace_back(arg->getValue());
        }
        else if (tp->isStringTy()) {
            format += "%s";
            printf_args.emplace_back(arg->getMem());
        } else {
            std::cerr << "[write/writeln] Unsupported type" << std::endl;
            return nullptr;
        }
    }
    if (new_line) {
        format += "\n";
    }
    printf_args[0] = builder.CreateGlobalStringPtr(format, "printf_format");
    return builder.CreateCall(printf_func, printf_args, "call_printf");
}

llvm::Value* GenSysRead(const std::vector<std::shared_ptr<ValueResult>> &args_list, bool new_line, llvm::Context &context, llvm::IRBuilder &builder, llvm::Module &module) {
    static llvm::Function *llvm_scanf = nullptr;
    if (llvm_scanf == nullptr) {
        //register printf
        std::vector<llvm::Type *> arg_types = {llvm::Type::getInt8PtrTy(context)};
        llvm::FunctionType *func_type = llvm::FunctionType::get(
            llvm::Type::getInt32Ty(),
            arg_types,
            true
        );
        llvm::Function *func = llvm::Function::Create(
            func_type,
            llvm::Function::ExternalLinkage,
            "scanf",
            &module
        );
        func->setCallingConv(llvm::CallingConv::C);
        llvm_scanf = func;
    }
    std::string format;
    std::vector<Value *> scanf_args;
    scanf_args.emplace_back(nullptr);
    for (auto arg: args_list) {
        OurType::PascalType *tp = arg->getType();
        if (tp->isIntegerTy()) {
            format += "%d";
        }
        else if (tp->isFloatingPointTy()) {
            format += "%lf";
        }
        else if (tp->isCharTy()) {
            format += "%c";
        }
        else if (tp->isStringTy()) {
            format += "%s";
        } else {
            std::cerr << "[write/writeln] Unsupported type" << std::endl;
            return nullptr;
        }
        scanf_args.emplace_back(arg->getMem());
    }
    if (new_line) {
        format += "%*[^\n]";
    }
    printf_args[0] = builder.CreateGlobalStringPtr(format, "scanf_format");
    llvm::Value* ret = builder.CreateCall(scanf_func, printf_args, "call_scanf");
    if (new_line) {
        //consume \n
        builder.CreateCall(scanf_func, builder.CreateGlobalStringPtr("%*c", "scanf_newline"), "call_scanf");
    }
    return ret;
}
bool Generator::isSysFunc(std::string id) {
    if (id == "write") return true;
    if (id == "writeln") return true;
    if (id == "read") return true;
    if (id == "readln") return true;
}

llvm::Value* Generator::genSysFunc(std::string id, const std::vector<std::shared_ptr<ValueResult> > &args_list) {
    if (id == "write") return GenSysWrite(args_list, false, this->context, this->builder, this->module);
    if (id == "writeln") return GenSysWrite(args_list, true, this->context, this->builder, this->module);
    if (id == "read") return GenSysRead(args_list, false, this->context, this->builder, this->module);
    if (id == "readln") return GenSysRead(args_list, true, this->context, this->builder, this->module);
}
