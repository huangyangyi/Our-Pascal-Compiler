#include "ast_stmt.h"
#include "../visitor.h"

#include <sstream>

ASTStmtList::ASTStmtList() {
    stmt_list.clear();
}

void ASTStmtList::addStmt(ASTStmt *stmt) { stmt_list.push_back(stmt); }

ASTStmt::ASTStmt(ASTNonLabelStmt *non_label_stmt, std::string label)
        : non_label_stmt(non_label_stmt), label(label) {}

ASTAssignStmt::ASTAssignStmt(ASTExpr *expr1, ASTExpr *expr2)
        : expr1(expr1), expr2(expr2) {};

ASTProcStmt::ASTProcStmt(std::string id, ASTExpressionList *expr_list)
        : id(id), expr_list(expr_list) {}

ASTIfStmt::ASTIfStmt(ASTExpr *expr, ASTStmt *stmt,
                     ASTElseClause *else_clause = nullptr)
        : expr(expr), stmt(stmt), else_clause(else_clause) {}

ASTElseClause::ASTElseClause(ASTStmt *stmt) : stmt(stmt) {}

ASTRepeatStmt::ASTRepeatStmt(ASTStmtList *stmt_list, ASTExpr *expr)
        : stmt_list_(stmt_list), expr_(expr) {}

ASTWhileStmt::ASTWhileStmt(ASTExpr *expr, ASTStmt *stmt)
        : expr_(expr), stmt_(stmt) {}

ASTForStmt::ASTForStmt(std::string id, ASTExpr *for_expr, ForDir dir,
                       ASTExpr *to_expr, ASTStmt *stmt)
        : id_(id), for_expr_(for_expr), dir_(dir), to_expr_(to_expr), stmt_(stmt) {}

ASTCaseStmt::ASTCaseStmt(ASTExpr *expr, ASTCaseExprList *case_expr_list)
        : expr_(expr), case_expr_list_(case_expr_list) {}

ASTCaseExprList::ASTCaseExprList() {}

void ASTCaseExprList::add_case_expr(ASTCaseExpr *expr) {
    this->case_expr_list_.push_back(expr);
}

ASTCaseExpr::ASTCaseExpr(ASTExpr *expr, ASTStmt *stmt)
        : expr_(expr), stmt_(stmt) {}

ASTGotoStmt::ASTGotoStmt(std::string label) : label_(label) {}

std::shared_ptr<VisitorResult> ASTStmt::Accept(Visitor *visitor) { return visitor->VisitASTStmt(this); }

const string &ASTStmt::getLabel() const {
    return label;
}

ASTNonLabelStmt *ASTStmt::getNonLabelStmt() const {
    return non_label_stmt;
}

std::shared_ptr<VisitorResult> ASTStmtList::Accept(Visitor *visitor) { return visitor->VisitASTStmtList(this); }

const vector<ASTStmt *> &ASTStmtList::getStmtList() const {
    return stmt_list;
}

std::shared_ptr<VisitorResult> ASTAssignStmt::Accept(Visitor *visitor) { return visitor->VisitASTAssignStmt(this); }

ASTExpr *ASTAssignStmt::getExpr1() const {
    return expr1;
}

ASTExpr *ASTAssignStmt::getExpr2() const {
    return expr2;
}

std::shared_ptr<VisitorResult> ASTProcStmt::Accept(Visitor *visitor) { return visitor->VisitASTProcStmt(this); }

const string &ASTProcStmt::getId() const {
    return id;
}

ASTExpressionList *ASTProcStmt::getExprList() const {
    return expr_list;
}

std::shared_ptr<VisitorResult> ASTIfStmt::Accept(Visitor *visitor) { return visitor->VisitASTIfStmt(this); }

ASTExpr *ASTIfStmt::getExpr() const {
    return expr;
}

ASTStmt *ASTIfStmt::getStmt() const {
    return stmt;
}

ASTElseClause *ASTIfStmt::getElseClause() const {
    return else_clause;
}

std::shared_ptr<VisitorResult> ASTElseClause::Accept(Visitor *visitor) { return visitor->VisitASTElseClause(this); }

ASTStmt *ASTElseClause::getStmt() const {
    return stmt;
}

std::shared_ptr<VisitorResult> ASTRepeatStmt::Accept(Visitor *visitor) { return visitor->VisitASTRepeatStmt(this); }

ASTStmtList *ASTRepeatStmt::getStmtList() const {
    return stmt_list_;
}

ASTExpr *ASTRepeatStmt::getExpr() const {
    return expr_;
}

std::shared_ptr<VisitorResult> ASTWhileStmt::Accept(Visitor *visitor) { return visitor->VisitASTWhileStmt(this); }

ASTExpr *ASTWhileStmt::getExpr() const {
    return expr_;
}

ASTStmt *ASTWhileStmt::getStmt() const {
    return stmt_;
}

std::shared_ptr<VisitorResult> ASTForStmt::Accept(Visitor *visitor) { return visitor->VisitASTForStmt(this); }

const string &ASTForStmt::getId() const {
    return id_;
}

ASTExpr *ASTForStmt::getForExpr() const {
    return for_expr_;
}

ASTExpr *ASTForStmt::getToExpr() const {
    return to_expr_;
}

ASTForStmt::ForDir ASTForStmt::getDir() const {
    return dir_;
}

ASTStmt *ASTForStmt::getStmt() const {
    return stmt_;
}

std::shared_ptr<VisitorResult> ASTCaseStmt::Accept(Visitor *visitor) { return visitor->VisitASTCaseStmt(this); }

ASTExpr *ASTCaseStmt::getExpr() const {
    return expr_;
}

ASTCaseExprList *ASTCaseStmt::getCaseExprList() const {
    return case_expr_list_;
}

std::shared_ptr<VisitorResult> ASTCaseExprList::Accept(Visitor *visitor) { return visitor->VisitASTCaseExprList(this); }

const vector<ASTCaseExpr *> &ASTCaseExprList::getCaseExprList() const {
    return case_expr_list_;
}

std::shared_ptr<VisitorResult> ASTCaseExpr::Accept(Visitor *visitor) { return visitor->VisitASTCaseExpr(this); }

ASTExpr *ASTCaseExpr::getExpr() const {
    return expr_;
}

ASTStmt *ASTCaseExpr::getStmt() const {
    return stmt_;
}

std::shared_ptr<VisitorResult> ASTGotoStmt::Accept(Visitor *visitor) { return visitor->VisitASTGotoStmt(this); }

const string &ASTGotoStmt::getLabel() const {
    return label_;
}

ASTExpr *ASTExitStmt::getExpr() const {
    return expr_;
}

ASTExitStmt::ASTExitStmt(ASTExpr *expr) : expr_(expr) {}

std::shared_ptr<VisitorResult> ASTExitStmt::Accept(Visitor *visitor) {
    return visitor->VisitASTExitStmt(this);
}


std::shared_ptr<VisitorResult> ASTBreakStmt::Accept(Visitor *visitor) {
    return visitor->VisitASTBreakStmt(this);
}
