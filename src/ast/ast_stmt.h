#ifndef OPC_AST_AST_STMT_H
#define OPC_AST_AST_STMT_H

#include "ast_base.h"
#include "ast_expr.h"

using namespace std;
class Visitor;

class ASTNode;

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
};

class ASTStmt : public ASTNode {
private:
    std::string label;
    ASTNonLabelStmt *non_label_stmt;

public:
    ASTStmt(ASTNonLabelStmt *non_label_stmt, std::string label = "");

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const std::string &getLabel() const;

    ASTNonLabelStmt *getNonLabelStmt() const;
};

class ASTStmtList : public ASTNonLabelStmt {
public:
    ASTStmtList();

    void addStmt(ASTStmt *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const std::vector<ASTStmt *> &getStmtList() const;

private:
    std::vector<ASTStmt *> stmt_list;
};

class ASTAssignStmt : public ASTNonLabelStmt {
public:
    ASTAssignStmt(ASTExpr *, ASTExpr *);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTExpr *getExpr1() const;

    ASTExpr *getExpr2() const;

private:
    ASTExpr *expr1;
    ASTExpr *expr2;
};

class ASTProcStmt : public ASTNonLabelStmt {
public:
    ASTProcStmt(std::string id, ASTExpressionList *expr = nullptr);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const std::string &getId() const;

    ASTExpressionList *getExprList() const;

private:
    std::string id;
    ASTExpressionList *expr_list;
};

class ASTIfStmt : public ASTNonLabelStmt {
public:
    ASTIfStmt(ASTExpr *, ASTStmt *, ASTElseClause *);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTExpr *getExpr() const;

    ASTStmt *getStmt() const;

    ASTElseClause *getElseClause() const;

private:
    ASTExpr *expr;
    ASTStmt *stmt;
    ASTElseClause *else_clause;
};

class ASTElseClause : public ASTNonLabelStmt {
public:
    ASTElseClause(ASTStmt *);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTStmt *getStmt() const;

private:
    ASTStmt *stmt;
};

class ASTRepeatStmt : public ASTNonLabelStmt {
public:
    ASTRepeatStmt(ASTStmtList *, ASTExpr *);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTStmtList *getStmtList() const;

    ASTExpr *getExpr() const;

private:
    ASTStmtList *stmt_list_;
    ASTExpr *expr_;
};

class ASTWhileStmt : public ASTNonLabelStmt {
public:
    ASTWhileStmt(ASTExpr *, ASTStmt *);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTExpr *getExpr() const;

    ASTStmt *getStmt() const;

private:
    ASTExpr *expr_;
    ASTStmt *stmt_;
};

class ASTForStmt : public ASTNonLabelStmt {
public:
    enum class ForDir {
        TO, DOWNTO
    };

    ASTForStmt(std::string id, ASTExpr *for_expr, ForDir dir, ASTExpr *to_expr,
               ASTStmt *stmt);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const string &getId() const;

    ASTExpr *getForExpr() const;

    ASTExpr *getToExpr() const;

    ForDir getDir() const;

    ASTStmt *getStmt() const;

private:
    std::string id_;
    ASTExpr *for_expr_, *to_expr_;
    ForDir dir_;
    ASTStmt *stmt_;
};

class ASTCaseStmt : public ASTNonLabelStmt {
public:
    ASTCaseStmt(ASTExpr *, ASTCaseExprList *);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTExpr *getExpr() const;

    ASTCaseExprList *getCaseExprList() const;

private:
    ASTExpr *expr_;
    ASTCaseExprList *case_expr_list_;
};

class ASTCaseExprList : public ASTNonLabelStmt {
public:
    ASTCaseExprList();

    void add_case_expr(ASTCaseExpr *);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const vector<ASTCaseExpr *> &getCaseExprList() const;

private:
    std::vector<ASTCaseExpr *> case_expr_list_;
};

class ASTCaseExpr : public ASTNonLabelStmt {
public:
    ASTCaseExpr(ASTExpr *, ASTStmt *);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTExpr *getExpr() const;

    ASTStmt *getStmt() const;

private:
    ASTExpr *expr_;
    ASTStmt *stmt_;
};

class ASTGotoStmt : public ASTNonLabelStmt {
public:
    ASTGotoStmt(std::string label);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const string &getLabel() const;

private:
    std::string label_;
};

class ASTExitStmt : public ASTNonLabelStmt {
public:
    ASTExitStmt(ASTExpr *expr = nullptr);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTExpr *getExpr() const;

private:
    ASTExpr *expr_;
};

class ASTBreakStmt : public ASTNonLabelStmt {
public:
    ASTBreakStmt() = default;

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);
};
#endif //OPC_AST_AST_STMT_H