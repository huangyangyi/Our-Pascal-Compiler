#ifndef OPC_VISITOR_H
#define OPC_VISITOR_H

class Visitor {
 public:
  virtual ~Visitor() = default;

  virtual void visitASTNode(Visitor*) = 0;
  virtual void visitASTNameList(Visitor*) = 0;

  virtual void visitASTExpr(Visitor*) = 0;
  virtual void visitASTExpressionList(Visitor*) = 0;
  virtual void visitASTBinaryExpr(Visitor*) = 0;
  virtual void visitASTConstValueExpr(Visitor*) = 0;
  virtual void visitASTIDExpr(Visitor*) = 0;

  virtual void visitASTProgramHead(Visitor*) = 0;
  virtual void visitASTRoutineHead(Visitor*) = 0;
  virtual void visitASTRoutineBody(Visitor*) = 0;
  virtual void visitASTRoutine(Visitor*) = 0;
  virtual void visitASTProgram(Visitor*) = 0;

  virtual void visitASTNonLabelStmt(Visitor*) = 0;
  virtual void visitASTStmt(Visitor*) = 0;
  virtual void visitASTStmtList(Visitor*) = 0;
  virtual void visitASTAssignStmt(Visitor*) = 0;
  virtual void visitASTProcStmt(Visitor*) = 0;
  virtual void visitASTCompoundStmt(Visitor*) = 0;
  virtual void visitASTIfStmt(Visitor*) = 0;
  virtual void visitASTElseClause(Visitor*) = 0;
  virtual void visitASTRepeatStmt(Visitor*) = 0;
  virtual void visitASTWhileStmt(Visitor*) = 0;
  virtual void visitASTForStmt(Visitor*) = 0;
  virtual void visitASTCaseStmt(Visitor*) = 0;
  virtual void visitASTCaseExprList(Visitor*) = 0;
  virtual void visitASTCaseExpr(Visitor*) = 0;
  virtual void visitASTGotoStmt(Visitor*) = 0;

  virtual void visitASTType(Visitor*) = 0;
  virtual void visitASTTypeDecl(Visitor*) = 0;
  virtual void visitASTSimpleTypeDecl(Visitor*) = 0;
  virtual void visitASTArrayTypeDecl(Visitor*) = 0;
  virtual void visitASTFieldDecl(Visitor*) = 0;
  virtual void visitASTFieldDeclList(Visitor*) = 0;
  virtual void visitASTRecordTypeDecl(Visitor*) = 0;
  virtual void visitASTTypeDefinition(Visitor*) = 0;
  virtual void visitASTTypeDeclList(Visitor*) = 0;
  virtual void visitASTTypePart(Visitor*) = 0;

  virtual void visitASTConstValue(Visitor*) = 0;
  virtual void visitASTConstExprList(Visitor*) = 0;
  virtual void visitASTConstPart(Visitor*) = 0;
  virtual void visitASTVarPart(Visitor*) = 0;
  virtual void visitASTVarDeclList(Visitor*) = 0;
  virtual void visitASTVarDecl(Visitor*) = 0;
};

#endif  // OPC_VISITOR_H
