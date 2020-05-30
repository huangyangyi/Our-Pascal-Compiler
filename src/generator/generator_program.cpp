#include "generator.h"
#include "../ast/ast_prog.h"
#include "generator_result.hpp"

std::shared_ptr<VisitorResult> Generator::VisitASTProgramHead(ASTProgramHead *node) {
    //do nothing
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTRoutineHead(ASTRoutineHead *node) {
    node->getConstPart()->Accept(this);
    node->getTypePart()->Accept(this);
    node->getVarPart()->Accept(this);
    node->getRoutinePart()->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTRoutineBody(ASTRoutineBody *node) {
    return node->getCompoundStmt()->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTRoutine(ASTRoutine *node) {
    node->getRoutineHead()->Accept(this);
    node->getRoutineBody()->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTProgram(ASTProgram *node) {
    node->getProgramHead()->Accept(this);
    this->block_stack.push_back(new CodeBlock());
    llvm::FunctionType *func_type = llvm::FunctionType::get(OurType::getLLVMType(this->context, OurType::INT_TYPE), false);
    llvm::Function *main_func = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "main", this->module);
    llvm::BasicBlock *entry = llvm::BasicBlock::Create(this->context, "entry", main_func);
    this->builder.SetInsertPoint(entry);
    node->getRoutine()->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTRoutinePart(ASTRoutinePart *node) {
    for (auto decl: node->getRoutineList()) decl->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTFuncProcBase(ASTFuncProcBase *node) {
    bool is_function = node->getIam() == ASTFuncProcBase::FuncType::FUNCTION;
    auto parameters = std::static_pointer_cast<TypeListResult>(
        is_function ? ((ASTFunctionDecl*)node)->getFunctionHead()->getParameters()->Accept(this)
                    : ((ASTProcedureDecl*)node)->getProcedureHead()->getParameters()->Accept(this));
    if (parameters == nullptr) return nullptr;
    OurType::PascalType *return_type = OurType::VOID_TYPE;
    std::string func_name;
    if (is_function){
        func_name = ((ASTFunctionDecl*)node)->getFunctionHead()->getFuncName();
        auto return_type_result = std::static_pointer_cast<TypeResult>(((ASTFunctionDecl*)node)->getFunctionHead()->getSimpleTypeDecl()->Accept(this));
        if (return_type_result == nullptr) return nullptr;
        return_type = return_type_result->getType();
    }else{
        func_name = ((ASTProcedureDecl*)node)->getProcedureHead()->getProcName();
    }
    llvm::Type *llvm_return_type = OurType::getLLVMType(context, return_type);
    auto name_list = parameters->getNameList();
    auto type_var_list = parameters->getTypeList();
    std::vector<llvm::Type*> llvm_type_list;
    std::vector<OurType::PascalType*> type_list;
    std::vector<bool> var_list;
    
    for (auto type: type_var_list){
        type_list.push_back(type->getType());
        var_list.push_back(type->is_var());
        llvm_type_list.push_back(llvm::PointerType::getUnqual(OurType::getLLVMType(context, type->getType())));
    }

    // adding local variables
    auto local_vars = this->getAllLocalVarNameType();
    std::vector<std::string> local_name_list = local_vars.first;
    std::vector<OurType::PascalType *> local_type_list = local_vars.second;
    for(int i = 0; i < local_name_list.size(); i++) {
        name_list.push_back(local_name_list[i]);
        type_list.push_back(local_type_list[i]);
        var_list.push_back(true);
        llvm_type_list.push_back(llvm::PointerType::getUnqual(OurType::getLLVMType(context, local_type_list[i])));
    }

    FuncSign *funcsign = new FuncSign(name_list, type_list, var_list, return_type);
    llvm::FunctionType *functionType = llvm::FunctionType::get(llvm_return_type, llvm_type_list, false);
    llvm::Function *function = llvm::Function::Create(functionType, llvm::GlobalValue::ExternalLinkage, func_name, module.get());

    this->getCurrentBlock()->set_function(func_name, function, funcsign);

    llvm::BasicBlock* oldBlock = this->builder.GetInsertBlock();
    llvm::BasicBlock* basicBlock = llvm::BasicBlock::Create(context, "entry", function, nullptr);
    this->builder.SetInsertPoint(basicBlock);

    // MODIFY PARAMETERS PASSING
    block_stack.push_back(new CodeBlock());
    int iter_i = 0;
    for(llvm::Function::arg_iterator arg_it = function->arg_begin(); arg_it != function->arg_end(); arg_it++) {
        if (var_list[iter_i]) {
            this->getCurrentBlock()->named_values[name_list[iter_i]] = (llvm::Value *)arg_it;
        } else {
            llvm::Value *value = this->builder.CreateLoad((llvm::Value *)arg_it);
            llvm::AllocaInst *mem = this->builder.CreateAlloca(
                OurType::getLLVMType(this->context, type_list[iter_i]),
                nullptr,
                name_list[iter_i]
            );
            this->builder.CreateStore(value, mem);
            this->getCurrentBlock()->named_values[name_list[iter_i]] = mem;
        }
    }    
    
    // add return mechanism
    if (is_function) {
        ((ASTFunctionDecl*)node)->getRoutine()->Accept(this);
        if (this->block_stack.size() == 1) {
            this->builder.CreateRet(llvm::ConstantInt::get(llvm::Type::getInt32Ty(), 0, true));
        } else {
            llvm::Value *ret = this->builder.CreateLoad(this->getCurrentBlock()->named_values[func_name]);
            this->builder.CreateRet(ret);
        }
    } else {
        ((ASTProcedureDecl*)node)->getRoutine()->Accept(this);
        this->builder.CreateRetVoid();
    }

    this->builder.SetInsertPoint(oldBlock);
    this->block_stack.pop_back();
}

std::shared_ptr<VisitorResult> Generator::VisitASTFunctionHead(ASTFunctionHead *node) {
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTProcedureHead(ASTProcedureHead *node) {
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTParaDeclList(ASTParaDeclList *node) {
    vector<std::string> name_list;
    std::vector<std::shared_ptr<TypeResult> > type_list;
    for (auto son: node->getParaDeclList()){
        auto temp_list = std::static_pointer_cast<TypeListResult>(son->Accept(this));
        name_list.insert(name_list.end(), temp_list->getNameList().begin(), temp_list->getNameList().end());
        type_list.insert(type_list.end(), temp_list->getTypeList().begin(), temp_list->getTypeList().end());
    }
    return std::make_shared<TypeListResult>(type_list, name_list);
}

std::shared_ptr<VisitorResult> Generator::VisitASTParaTypeList(ASTParaTypeList *node) {
    std::shared_ptr<VisitorResult> list;
    if (node->getParaList()->isVar())
        list = ((ASTVarParaList*)(node->getParaList()))->Accept(this);
    else
        list = ((ASTValParaList*)(node->getParaList()))->Accept(this);
    
    auto name_list = std::static_pointer_cast<NameListResult>(list)->getNameList()->GetIdentifierList();
    auto type_value = std::static_pointer_cast<TypeResult>(node->getSimpleTypeDecl()->Accept(this));
    if (node->getParaList()->isVar())
        type_value->set_var();
    std::vector<std::shared_ptr<TypeResult> > type_list(name_list.size(), type_value);
    return std::make_shared<TypeListResult>(type_list, name_list);
}

std::shared_ptr<VisitorResult> Generator::VisitASTVarParaList(ASTVarParaList *node) {
    return std::make_shared<NameListResult>(node->getNameList());
}

std::shared_ptr<VisitorResult> Generator::VisitASTValParaList(ASTValParaList *node) {
    return std::make_shared<NameListResult>(node->getNameList());
}