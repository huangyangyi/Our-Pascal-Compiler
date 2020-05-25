#ifndef OPC_GENERATOR_H
#define OPC_GENERATOR_H

#include "../visitor.h"
#include<llvm/IR/IRBuilder.h>
class Generator: Visitor {
 private:
  llvm::IRBuilder<> builder;
  llvm::LLVMContext context;
  std::unique_ptr<llvm::Module> module;
  std::map<std::string, llvm::Value *> named_values;
  
 public:
  Generator();
  ~Generator() ;
  virtual std::shared_ptr<VisitorResult> VisitASTNode(ASTNode* node);
  virtual std::shared_ptr<VisitorResult> VisitASTNameList(ASTNameList* node);
  virtual std::shared_ptr<VisitorResult> VisitASTExpressionList(ASTExpressionList* node);
  virtual std::shared_ptr<VisitorResult> VisitASTBinaryExpr(ASTBinaryExpr* node);
  virtual std::shared_ptr<VisitorResult> VisitASTUnaryExpr(ASTUnaryExpr* node);
  virtual std::shared_ptr<VisitorResult> VisitASTPropExpr(ASTPropExpr* node);
  virtual std::shared_ptr<VisitorResult> VisitASTConstValueExpr(ASTConstValueExpr* node);
  virtual std::shared_ptr<VisitorResult> VisitASTFuncCall(ASTFuncCall* node);
  virtual std::shared_ptr<VisitorResult> VisitASTIDExpr(ASTIDExpr* node);
  virtual std::shared_ptr<VisitorResult> VisitASTArrayExpr(ASTArrayExpr* node);
  virtual std::shared_ptr<VisitorResult> VisitASTProgramHead(ASTProgramHead* node);
  virtual std::shared_ptr<VisitorResult> VisitASTRoutineHead(ASTRoutineHead* node);
  virtual std::shared_ptr<VisitorResult> VisitASTRoutineBody(ASTRoutineBody* node);
  virtual std::shared_ptr<VisitorResult> VisitASTRoutine(ASTRoutine* node);
  virtual std::shared_ptr<VisitorResult> VisitASTProgram(ASTProgram* node);
  virtual std::shared_ptr<VisitorResult> VisitASTRoutinePart(ASTRoutinePart* node);
  virtual std::shared_ptr<VisitorResult> VisitASTFuncProcBase(ASTFuncProcBase* node);
  virtual std::shared_ptr<VisitorResult> VisitASTFunctionDecl(ASTFunctionDecl* node);
  virtual std::shared_ptr<VisitorResult> VisitASTFunctionHead(ASTFunctionHead* node);
  virtual std::shared_ptr<VisitorResult> VisitASTProcedureDecl(ASTProcedureDecl* node);
  virtual std::shared_ptr<VisitorResult> VisitASTProcedureHead(ASTProcedureHead* node);
  virtual std::shared_ptr<VisitorResult> VisitASTParaDeclList(ASTParaDeclList* node);
  virtual std::shared_ptr<VisitorResult> VisitASTParaTypeList(ASTParaTypeList* node);
  virtual std::shared_ptr<VisitorResult> VisitASTVarParaList(ASTVarParaList* node);
  virtual std::shared_ptr<VisitorResult> VisitASTValParaList(ASTValParaList* node);
  virtual std::shared_ptr<VisitorResult> VisitASTNonLabelStmt(ASTNonLabelStmt* node);
  virtual std::shared_ptr<VisitorResult> VisitASTStmt(ASTStmt* node);
  virtual std::shared_ptr<VisitorResult> VisitASTStmtList(ASTStmtList* node);
  virtual std::shared_ptr<VisitorResult> VisitASTAssignStmt(ASTAssignStmt* node);
  virtual std::shared_ptr<VisitorResult> VisitASTProcStmt(ASTProcStmt* node);
  virtual std::shared_ptr<VisitorResult> VisitASTIfStmt(ASTIfStmt* node);
  virtual std::shared_ptr<VisitorResult> VisitASTElseClause(ASTElseClause* node);
  virtual std::shared_ptr<VisitorResult> VisitASTRepeatStmt(ASTRepeatStmt* node);
  virtual std::shared_ptr<VisitorResult> VisitASTWhileStmt(ASTWhileStmt* node);
  virtual std::shared_ptr<VisitorResult> VisitASTForStmt(ASTForStmt* node);
  virtual std::shared_ptr<VisitorResult> VisitASTCaseStmt(ASTCaseStmt* node);
  virtual std::shared_ptr<VisitorResult> VisitASTCaseExprList(ASTCaseExprList* node);
  virtual std::shared_ptr<VisitorResult> VisitASTCaseExpr(ASTCaseExpr* node);
  virtual std::shared_ptr<VisitorResult> VisitASTGotoStmt(ASTGotoStmt* node);
  virtual std::shared_ptr<VisitorResult> VisitASTType(ASTType* node);
  virtual std::shared_ptr<VisitorResult> VisitASTSimpleTypeDecl(ASTSimpleTypeDecl* node);
  virtual std::shared_ptr<VisitorResult> VisitASTArrayTypeDecl(ASTArrayTypeDecl* node);
  virtual std::shared_ptr<VisitorResult> VisitASTFieldDecl(ASTFieldDecl* node);
  virtual std::shared_ptr<VisitorResult> VisitASTFieldDeclList(ASTFieldDeclList* node);
  virtual std::shared_ptr<VisitorResult> VisitASTRecordTypeDecl(ASTRecordTypeDecl* node);
  virtual std::shared_ptr<VisitorResult> VisitASTTypeDefinition(ASTTypeDefinition* node);
  virtual std::shared_ptr<VisitorResult> VisitASTTypeDeclList(ASTTypeDeclList* node);
  virtual std::shared_ptr<VisitorResult> VisitASTTypePart(ASTTypePart* node);
  virtual std::shared_ptr<VisitorResult> VisitASTConstValue(ASTConstValue* node);
  virtual std::shared_ptr<VisitorResult> VisitASTConstExprList(ASTConstExprList* node);
  virtual std::shared_ptr<VisitorResult> VisitASTConstExpr(ASTConstExpr* node);
  virtual std::shared_ptr<VisitorResult> VisitASTConstPart(ASTConstPart* node);
  virtual std::shared_ptr<VisitorResult> VisitASTVarPart(ASTVarPart* node);
  virtual std::shared_ptr<VisitorResult> VisitASTVarDeclList(ASTVarDeclList* node);
  virtual std::shared_ptr<VisitorResult> VisitASTVarDecl(ASTVarDecl* node);

};

#endif OPC_GENERATOR_H