#include "generator.h"
#include "../ast/ast_prog.h"
#include "generator_result.hpp"

std::shared_ptr<VisitorResult> Generator::VisitASTProgramHead(ASTProgramHead *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTRoutineHead(ASTRoutineHead *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTRoutineBody(ASTRoutineBody *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTRoutine(ASTRoutine *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTProgram(ASTProgram *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTRoutinePart(ASTRoutinePart *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTFuncProcBase(ASTFuncProcBase *node) {
    bool is_function = node->getIam() == ASTFuncProcBase::FuncType::FUNCTION);
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
    auto type_var_list = parameters->getTypeList();
    std::vector<llvm::Type*> llvm_type_list;
    std::vector<OurType::PascalType*> type_list;
    std::vector<bool> var_list;
    for (auto type: type_var_list){
        type_list.push_back(type->getType());
        var_list.push_back(type->is_var());
        llvm_type_list.push_back(OurType::getLLVMType(context, type->getType()));
    }
    FuncSign *sem_func = new FuncSign(parameters->getNameList(), type_list, var_list, return_type);
    llvm::FunctionType *functionType = llvm::FunctionType::get(llvm_return_type, llvm_type_list, false);
    llvm::Function *function = llvm::Function::Create(functionType, llvm::GlobalValue::ExternalLinkage, func_name, module.get());

    BasicBlock* basicBlock = BasicBlock::Create(context.llvmContext, "entry", function, nullptr);
    builder.SetInsertPoint(basicBlock);
    int cur = 0;
    for(auto &ir_arg_it: function->args()){
        ir_arg_it.setName(name_list[cur]);


        cur++;
    }
    //To be continued...
}

std::shared_ptr<VisitorResult> Generator::VisitASTFunctionDecl(ASTFunctionDecl *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTFunctionHead(ASTFunctionHead *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTProcedureDecl(ASTProcedureDecl *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTProcedureHead(ASTProcedureHead *node) {}

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