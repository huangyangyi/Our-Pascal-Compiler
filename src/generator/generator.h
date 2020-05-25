#include "../visitor.h"
#include<llvm/IR/IRBuilder.h>
using namespace std;
class Generator: Visitor {
 private:
  llvm::IRBuilder<> builder;
  llvm::LLVMContext context;
  std::unique_ptr<llvm::Module> module;
  std::map<std::string, llvm::Value *> named_values;
  
 public:
  Generator();
  ~Generator() ;
  virtual shared_ptr<VisitorResult> VisitASTNode(ASTNode* node);
  virtual shared_ptr<VisitorResult> VisitASTNameList(ASTNameList* node);
  virtual shared_ptr<VisitorResult> VisitASTExpressionList(ASTExpressionList* node);
  virtual shared_ptr<VisitorResult> VisitASTBinaryExpr(ASTBinaryExpr* node);
  virtual shared_ptr<VisitorResult> VisitASTUnaryExpr(ASTUnaryExpr* node);
  virtual shared_ptr<VisitorResult> VisitASTPropExpr(ASTPropExpr* node);
  virtual shared_ptr<VisitorResult> VisitASTConstValueExpr(ASTConstValueExpr* node);
  virtual shared_ptr<VisitorResult> VisitASTFuncCall(ASTFuncCall* node);
  virtual shared_ptr<VisitorResult> VisitASTIDExpr(ASTIDExpr* node);
  virtual shared_ptr<VisitorResult> VisitASTArrayExpr(ASTArrayExpr* node);
  virtual shared_ptr<VisitorResult> VisitASTProgramHead(ASTProgramHead* node);
  virtual shared_ptr<VisitorResult> VisitASTRoutineHead(ASTRoutineHead* node);
  virtual shared_ptr<VisitorResult> VisitASTRoutineBody(ASTRoutineBody* node);
  virtual shared_ptr<VisitorResult> VisitASTRoutine(ASTRoutine* node);
  virtual shared_ptr<VisitorResult> VisitASTProgram(ASTProgram* node);
  virtual shared_ptr<VisitorResult> VisitASTRoutinePart(ASTRoutinePart* node);
  virtual shared_ptr<VisitorResult> VisitASTFuncProcBase(ASTFuncProcBase* node);
  virtual shared_ptr<VisitorResult> VisitASTFunctionDecl(ASTFunctionDecl* node);
  virtual shared_ptr<VisitorResult> VisitASTFunctionHead(ASTFunctionHead* node);
  virtual shared_ptr<VisitorResult> VisitASTProcedureDecl(ASTProcedureDecl* node);
  virtual shared_ptr<VisitorResult> VisitASTProcedureHead(ASTProcedureHead* node);
  virtual shared_ptr<VisitorResult> VisitASTParaDeclList(ASTParaDeclList* node);
  virtual shared_ptr<VisitorResult> VisitASTParaTypeList(ASTParaTypeList* node);
  virtual shared_ptr<VisitorResult> VisitASTVarParaList(ASTVarParaList* node);
  virtual shared_ptr<VisitorResult> VisitASTValParaList(ASTValParaList* node);
  virtual shared_ptr<VisitorResult> VisitASTNonLabelStmt(ASTNonLabelStmt* node);
  virtual shared_ptr<VisitorResult> VisitASTStmt(ASTStmt* node);
  virtual shared_ptr<VisitorResult> VisitASTStmtList(ASTStmtList* node);
  virtual shared_ptr<VisitorResult> VisitASTAssignStmt(ASTAssignStmt* node);
  virtual shared_ptr<VisitorResult> VisitASTProcStmt(ASTProcStmt* node);
  virtual shared_ptr<VisitorResult> VisitASTIfStmt(ASTIfStmt* node);
  virtual shared_ptr<VisitorResult> VisitASTElseClause(ASTElseClause* node);
  virtual shared_ptr<VisitorResult> VisitASTRepeatStmt(ASTRepeatStmt* node);
  virtual shared_ptr<VisitorResult> VisitASTWhileStmt(ASTWhileStmt* node);
  virtual shared_ptr<VisitorResult> VisitASTForStmt(ASTForStmt* node);
  virtual shared_ptr<VisitorResult> VisitASTCaseStmt(ASTCaseStmt* node);
  virtual shared_ptr<VisitorResult> VisitASTCaseExprList(ASTCaseExprList* node);
  virtual shared_ptr<VisitorResult> VisitASTCaseExpr(ASTCaseExpr* node);
  virtual shared_ptr<VisitorResult> VisitASTGotoStmt(ASTGotoStmt* node);
  virtual shared_ptr<VisitorResult> VisitASTType(ASTType* node);
  virtual shared_ptr<VisitorResult> VisitASTSimpleTypeDecl(ASTSimpleTypeDecl* node);
  virtual shared_ptr<VisitorResult> VisitASTArrayTypeDecl(ASTArrayTypeDecl* node);
  virtual shared_ptr<VisitorResult> VisitASTFieldDecl(ASTFieldDecl* node);
  virtual shared_ptr<VisitorResult> VisitASTFieldDeclList(ASTFieldDeclList* node);
  virtual shared_ptr<VisitorResult> VisitASTRecordTypeDecl(ASTRecordTypeDecl* node);
  virtual shared_ptr<VisitorResult> VisitASTTypeDefinition(ASTTypeDefinition* node);
  virtual shared_ptr<VisitorResult> VisitASTTypeDeclList(ASTTypeDeclList* node);
  virtual shared_ptr<VisitorResult> VisitASTTypePart(ASTTypePart* node);
  virtual shared_ptr<VisitorResult> VisitASTConstValue(ASTConstValue* node);
  virtual shared_ptr<VisitorResult> VisitASTConstExprList(ASTConstExprList* node);
  virtual shared_ptr<VisitorResult> VisitASTConstExpr(ASTConstExpr* node);
  virtual shared_ptr<VisitorResult> VisitASTConstPart(ASTConstPart* node);
  virtual shared_ptr<VisitorResult> VisitASTVarPart(ASTVarPart* node);
  virtual shared_ptr<VisitorResult> VisitASTVarDeclList(ASTVarDeclList* node);
  virtual shared_ptr<VisitorResult> VisitASTVarDecl(ASTVarDecl* node);

};