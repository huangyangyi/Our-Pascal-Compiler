#ifndef OPC_GENERATOR_H
#define OPC_GENERATOR_H

#include "../visitor.h"
#include "../type/type.hpp"
#include<llvm/IR/IRBuilder.h>


struct FuncSign{
public:
    FuncSign(std::vector<std::string> name_list, std::vector<PascalType*> type_list, std::vector<bool> is_var, PascalType* return_type = nullptr)
        :name_list_(name_list), type_list_(type_list), is_var_(is_var), return_type_(return_type){
            if (return_type == nullptr)
                return_type_ = VOID_TYPE;
        }
    std::vector<PascalType*> getTypeList(){return type_list_;}
    std::vector<std::string> getNameList(){return name_list_;}
    std::vector<bool> getIsVar(){return is_var_;}
    PascalType* getReturnType(){return return_type_;}
private:
    std::vector<PascalType*> type_list_;
    std::vector<std::string> name_list_;
    std::vector<bool> is_var_;
    PascalType* return_type_;
};

class CodeBlock {
    public:
    std::map<string, llvm::Value*> named_values;
    std::map<string, Type::PascalType*> named_types;
    std::map<std::string, llvm::Function*> named_functions;
    std::map<std::string, FuncSign*> function_parameters;
    std::map<int, llvm::BasicBlock *> labels;
    bool isType(std::string id){
        return named_types.find(id) != named_types.end() && named_values.find(id) == named_values.end();
    }
    bool isValue(std::string id){
        return named_values.find(id) != named_values.end();
    }
    llvm::Function *find_function(std::string id){
        if (named_functions.find(id) == named_functions.end())
            return nullptr;
        return named_functions[id];
    }
    FuncSign *find_function_parameters(std::string id){
        if (function_parameters.find(id) == function_parameters.end())
            return nullptr;
        return function_parameters[id];
    }
};


class Generator : Visitor {
private:
    llvm::IRBuilder<> builder;
    llvm::LLVMContext context;
    std::unique_ptr<llvm::Module> module;
    std::vector<CodeBlock*> block_stack;
    std::map<string, llvm::Constant*> named_constants;
    
    friend class OurType::EnumType;
public:
    Generator();

    ~Generator();

    CodeBlock* getCurrentBlock(void) { return *(this->block_stack.rbegin()); }

    void genAssign(llvm::Value* dest_ptr, OurType::PascalType *dest_type, llvm::Value* src, OurType::PascalType *src_type);

    llvm::Value* genMatch(llvm::Value* dest, OurType::PascalType *dest_type, llvm::Value* src, OurType::PascalType *src_type);
    
    llvm::Value* genFuncCall(std::string id, const std::vector<ValueResult *> &args_list);

    llvm::Value* genSysFunc(std::string id, const std::vector<ValueResult *> &args_list);

    bool isSysFunc(std::string id);

    virtual std::shared_ptr<VisitorResult> VisitASTNode(ASTNode *node);

    virtual std::shared_ptr<VisitorResult> VisitASTNameList(ASTNameList *node);

    virtual std::shared_ptr<VisitorResult> VisitASTExpressionList(ASTExpressionList *node);

    virtual std::shared_ptr<VisitorResult> VisitASTBinaryExpr(ASTBinaryExpr *node);

    virtual std::shared_ptr<VisitorResult> VisitASTUnaryExpr(ASTUnaryExpr *node);

    virtual std::shared_ptr<VisitorResult> VisitASTPropExpr(ASTPropExpr *node);

    virtual std::shared_ptr<VisitorResult> VisitASTConstValueExpr(ASTConstValueExpr *node);

    virtual std::shared_ptr<VisitorResult> VisitASTFuncCall(ASTFuncCall *node);

    virtual std::shared_ptr<VisitorResult> VisitASTIDExpr(ASTIDExpr *node);

    virtual std::shared_ptr<VisitorResult> VisitASTArrayExpr(ASTArrayExpr *node);

    virtual std::shared_ptr<VisitorResult> VisitASTProgramHead(ASTProgramHead *node);

    virtual std::shared_ptr<VisitorResult> VisitASTRoutineHead(ASTRoutineHead *node);

    virtual std::shared_ptr<VisitorResult> VisitASTRoutineBody(ASTRoutineBody *node);

    virtual std::shared_ptr<VisitorResult> VisitASTRoutine(ASTRoutine *node);

    virtual std::shared_ptr<VisitorResult> VisitASTProgram(ASTProgram *node);

    virtual std::shared_ptr<VisitorResult> VisitASTRoutinePart(ASTRoutinePart *node);

    virtual std::shared_ptr<VisitorResult> VisitASTFuncProcBase(ASTFuncProcBase *node);

    virtual std::shared_ptr<VisitorResult> VisitASTFunctionDecl(ASTFunctionDecl *node);

    virtual std::shared_ptr<VisitorResult> VisitASTFunctionHead(ASTFunctionHead *node);

    virtual std::shared_ptr<VisitorResult> VisitASTProcedureDecl(ASTProcedureDecl *node);

    virtual std::shared_ptr<VisitorResult> VisitASTProcedureHead(ASTProcedureHead *node);

    virtual std::shared_ptr<VisitorResult> VisitASTParaDeclList(ASTParaDeclList *node);

    virtual std::shared_ptr<VisitorResult> VisitASTParaTypeList(ASTParaTypeList *node);

    virtual std::shared_ptr<VisitorResult> VisitASTVarParaList(ASTVarParaList *node);

    virtual std::shared_ptr<VisitorResult> VisitASTValParaList(ASTValParaList *node);

    virtual std::shared_ptr<VisitorResult> VisitASTNonLabelStmt(ASTNonLabelStmt *node);

    virtual std::shared_ptr<VisitorResult> VisitASTStmt(ASTStmt *node);

    virtual std::shared_ptr<VisitorResult> VisitASTStmtList(ASTStmtList *node);

    virtual std::shared_ptr<VisitorResult> VisitASTAssignStmt(ASTAssignStmt *node);

    virtual std::shared_ptr<VisitorResult> VisitASTProcStmt(ASTProcStmt *node);

    virtual std::shared_ptr<VisitorResult> VisitASTIfStmt(ASTIfStmt *node);

    virtual std::shared_ptr<VisitorResult> VisitASTElseClause(ASTElseClause *node);

    virtual std::shared_ptr<VisitorResult> VisitASTRepeatStmt(ASTRepeatStmt *node);

    virtual std::shared_ptr<VisitorResult> VisitASTWhileStmt(ASTWhileStmt *node);

    virtual std::shared_ptr<VisitorResult> VisitASTForStmt(ASTForStmt *node);

    virtual std::shared_ptr<VisitorResult> VisitASTCaseStmt(ASTCaseStmt *node);

    virtual std::shared_ptr<VisitorResult> VisitASTCaseExprList(ASTCaseExprList *node);

    virtual std::shared_ptr<VisitorResult> VisitASTCaseExpr(ASTCaseExpr *node);

    virtual std::shared_ptr<VisitorResult> VisitASTGotoStmt(ASTGotoStmt *node);

    virtual std::shared_ptr<VisitorResult> VisitASTType(ASTType *node);

    virtual std::shared_ptr<VisitorResult> VisitASTSimpleTypeDecl(ASTSimpleTypeDecl *node);

    virtual std::shared_ptr<VisitorResult> VisitASTArrayTypeDecl(ASTArrayTypeDecl *node);

    virtual std::shared_ptr<VisitorResult> VisitASTFieldDecl(ASTFieldDecl *node);

    virtual std::shared_ptr<VisitorResult> VisitASTFieldDeclList(ASTFieldDeclList *node);

    virtual std::shared_ptr<VisitorResult> VisitASTRecordTypeDecl(ASTRecordTypeDecl *node);

    virtual std::shared_ptr<VisitorResult> VisitASTTypeDefinition(ASTTypeDefinition *node);

    virtual std::shared_ptr<VisitorResult> VisitASTTypeDeclList(ASTTypeDeclList *node);

    virtual std::shared_ptr<VisitorResult> VisitASTTypePart(ASTTypePart *node);

    virtual std::shared_ptr<VisitorResult> VisitASTConstValue(ASTConstValue *node);

    virtual std::shared_ptr<VisitorResult> VisitASTConstExprList(ASTConstExprList *node);

    virtual std::shared_ptr<VisitorResult> VisitASTConstExpr(ASTConstExpr *node);

    virtual std::shared_ptr<VisitorResult> VisitASTConstPart(ASTConstPart *node);

    virtual std::shared_ptr<VisitorResult> VisitASTVarPart(ASTVarPart *node);

    virtual std::shared_ptr<VisitorResult> VisitASTVarDeclList(ASTVarDeclList *node);

    virtual std::shared_ptr<VisitorResult> VisitASTVarDecl(ASTVarDecl *node);

};

#endif OPC_GENERATOR_H