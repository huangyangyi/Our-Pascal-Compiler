#ifndef OPC_AST_AST_STMT_H
#define OPC_AST_AST_STMT_H

#include "ast_base.h"
#include "ast_expr.h"

class ASTNonLabelStmt;
class ASTStmt;
class ASTStmtList;
class ASTAssignStmt;
class ASTProcStmt;
class ASTIfStmt;
class ASTElseClause;
class ASTRepeatStmt;
class ASTWhileStmt;
class ASTForStmt;
class ASTCaseStmt;
class ASTCaseExprList;
class ASTCaseExpr;
class ASTGotoStmt;

class ASTNonLabelStmt : public ASTNode {
  // virtual void Print(GraphGenerator *graph); //Do not implement print() in this class.
};

class ASTStmt : public ASTNode {
private:
  std::string label;
  ASTNonLabelStmt* non_label_stmt;

public:
  ASTStmt(ASTNonLabelStmt *non_label_stmt, std::string label = "");
  virtual void Print(GraphGenerator *graph);
};

class ASTStmtList : public ASTNode {
public:
  ASTStmtList(ASTStmt *);
  void addStmt(ASTStmt *);
  virtual void Print(GraphGenerator *graph);

private:
  std::vector<ASTStmt *> stmt_list;
};

class ASTAssignStmt : public ASTNonLabelStmt {
public:
  ASTAssignStmt(ASTExpr *, ASTExpr *);
  virtual void Print(GraphGenerator *);

private:
  ASTExpr *expr1;
  ASTExpr *expr2;
};

class ASTProcStmt : public ASTNonLabelStmt {
public:
  ASTProcStmt(std::string id, ASTExpressionList *expr = nullptr);
  virtual void Print(GraphGenerator *);

private:
  std::string id;
  ASTExpressionList *expr_list;
};

class ASTIfStmt : public ASTNonLabelStmt {
public:
  ASTIfStmt(ASTExpr *, ASTStmt *, ASTElseClause *);
  virtual void Print(GraphGenerator *);

private:
  ASTExpr *expr;
  ASTStmt *stmt;
  ASTElseClause *else_clause;
};

class ASTElseClause : public ASTNonLabelStmt {
public:
  ASTElseClause(ASTStmt *);
  virtual void Print(GraphGenerator *);

private:
  ASTStmt *stmt;
};

class ASTRepeatStmt : public ASTNode {
public:
  ASTRepeatStmt(ASTStmtList *, ASTExpr *);
  virtual void Print(GraphGenerator *);

private:
  ASTStmtList *stmt_list_;
  ASTExpr *expr_;
};

class ASTWhileStmt : public ASTNode {
public:
  ASTWhileStmt(ASTExpr *, ASTStmt *);
  virtual void Print(GraphGenerator *);

private:
  ASTExpr *expr_;
  ASTStmt *stmt_;
};

class ASTForStmt : public ASTNonLabelStmt {
public:
  enum class ForDir { TO, DOWNTO };
  ASTForStmt(std::string id, ASTExpr *for_expr, ForDir dir, ASTExpr *to_expr,
             ASTStmt *stmt);
  virtual void Print(GraphGenerator *);

private:
  std::string id_;
  ASTExpr *for_expr_, *to_expr_;
  ForDir dir_;
  ASTStmt *stmt_;
};

class ASTCaseStmt : public ASTNode {
public:
  ASTCaseStmt(ASTExpr *, ASTCaseExprList *);
  virtual void Print(GraphGenerator *);

private:
  ASTExpr *expr_;
  ASTCaseExprList *case_expr_list_;
};

class ASTCaseExprList : public ASTNode {
public:
  ASTCaseExprList();
  void add_case_expr(ASTCaseExpr *);
  virtual void Print(GraphGenerator *);

private:
  std::vector<ASTCaseExpr *> case_expr_list_;
};

class ASTCaseExpr : public ASTNode {
public:
  ASTCaseExpr(ASTConstValue *, ASTStmt *);
  virtual void Print(GraphGenerator *);

private:
  ASTConstValue *const_value_;
  ASTStmt *stmt_;
};

class ASTGotoStmt : public ASTNode {
public:
  ASTGotoStmt(std::string label);
  virtual void Print(GraphGenerator *);

private:
  std::string label_;
};

#endif //OPC_AST_AST_STMT_H