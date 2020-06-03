#ifndef OPC_GENERATOR_H
#define OPC_GENERATOR_H

#include <iostream>
#include "../visitor.h"
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>

namespace OurType {
    class EnumType;

    class PascalType;

    extern PascalType *const VOID_TYPE;
};

class ValueResult;

class FuncSign {
public:
    FuncSign(int n_local, std::vector<std::string> name_list, std::vector<OurType::PascalType *> type_list,
             std::vector<bool> is_var, OurType::PascalType *return_type = nullptr)
            : name_list_(name_list), type_list_(type_list), is_var_(is_var), return_type_(return_type),
              n_local_variables(n_local) {
        if (return_type == nullptr)
            return_type_ = OurType::VOID_TYPE;
    }


    std::vector<OurType::PascalType *> getTypeList() { return type_list_; }

    std::vector<std::string> getNameList() { return name_list_; }

    std::vector<bool> getVarList() { return is_var_; }

    OurType::PascalType *getReturnType() { return return_type_; }

    int getLocalVariablesNum() { return this->n_local_variables; }

private:
    int n_local_variables; // used for parameter passing
    std::vector<OurType::PascalType *> type_list_;
    std::vector<std::string> name_list_;
    std::vector<bool> is_var_;
    OurType::PascalType *return_type_;
};

class CodeBlock {
public:
    std::map<std::string, llvm::Value *> named_values;
    std::map<std::string, OurType::PascalType *> named_types;
    std::map<std::string, llvm::Function *> named_functions;
    std::map<std::string, FuncSign *> named_funcsigns;
    std::map<int, llvm::BasicBlock *> labels;
    std::string block_name;
    bool is_function;
    std::vector<llvm::BasicBlock *> loop_breaks;

    bool isType(std::string id, bool check_defined = false) {
        return named_types.find(id) != named_types.end() &&
               (named_values.find(id) == named_values.end() || check_defined);
    }

    bool isValue(std::string id) {
        return named_values.find(id) != named_values.end();
    }

    llvm::Function *find_function(std::string id) {
        if (named_functions.find(id) == named_functions.end())
            return nullptr;
        return named_functions[id];
    }

    FuncSign *find_funcsign(std::string id) {
        if (named_funcsigns.find(id) == named_funcsigns.end())
            return nullptr;
        return named_funcsigns[id];
    }

    void set_function(std::string id, llvm::Function *function, FuncSign *funcsign) {
        named_funcsigns[id] = funcsign;
        named_functions[id] = function;
    }
};

class Generator : public Visitor {
public:
    int temp_variable_count = 0;
    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> module;
    std::vector<CodeBlock *> block_stack;
    std::map<std::string, llvm::Constant *> named_constants;
    std::vector<std::string> error_message;
    std::vector<std::pair<int, int> > error_position;

    friend class OurType::EnumType;

public:
    Generator();

    ~Generator();

    void Save(std::string path);

    void
    genAssign(llvm::Value *dest_ptr, OurType::PascalType *dest_type, llvm::Value *src, OurType::PascalType *src_type);

    llvm::Value *genSysFunc(std::string id, const std::vector<std::shared_ptr<ValueResult>> &args_list);

    std::shared_ptr<VisitorResult>
    RecordErrorMessage(std::string cur_error_message, std::pair<int, int> location = std::make_pair(-1, -1));

    bool hasError();

    void printError();

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

    virtual std::shared_ptr<VisitorResult> VisitASTProcedureDecl(ASTProcedureDecl *node);

    virtual std::shared_ptr<VisitorResult> VisitASTFunctionHead(ASTFunctionHead *node);

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

    shared_ptr<VisitorResult> VisitASTExitStmt(ASTExitStmt *node);

    shared_ptr<VisitorResult> VisitASTBreakStmt(ASTBreakStmt *node);

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


    CodeBlock *getCurrentBlock(void);

    pair<vector<std::string>, vector<OurType::PascalType *>> getAllLocalVarNameType();

    OurType::PascalType *getVarType(std::string id);
};

#endif //OPC_GENERATOR_H