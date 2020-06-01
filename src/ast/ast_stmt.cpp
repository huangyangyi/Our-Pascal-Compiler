#include "ast_stmt.h"
#include "../visitor.h"

#include <sstream>

ASTStmtList::ASTStmtList() {
    stmt_list.clear();
}

void ASTStmtList::addStmt(ASTStmt *stmt) { stmt_list.push_back(stmt); }

void ASTStmtList::Print(GraphGenerator *g) {
    g->AddNode("stmt_list", this->line(), this->col());
    for (int i = 0; i < stmt_list.size(); i++) stmt_list[i]->Print(g);
    g->Pop();
}

ASTStmt::ASTStmt(ASTNonLabelStmt *non_label_stmt, std::string label)
        : non_label_stmt(non_label_stmt), label(label) {}

void ASTStmt::Print(GraphGenerator *g) {
    if (label == "") {
        non_label_stmt->Print(g);
    } else {
        g->AddNode("label_stmt " + label, this->line(), this->col());
        non_label_stmt->Print(g);
        g->Pop();
    }
}

ASTAssignStmt::ASTAssignStmt(ASTExpr *expr1, ASTExpr *expr2)
        : expr1(expr1), expr2(expr2) {};

void ASTAssignStmt::Print(GraphGenerator *g) {
    g->AddNode("assign_stmt", this->line(), this->col());
    expr1->Print(g);
    expr2->Print(g);
    g->Pop();
}

ASTProcStmt::ASTProcStmt(std::string id, ASTExpressionList *expr_list)
        : id(id), expr_list(expr_list) {}

void ASTProcStmt::Print(GraphGenerator *g) {
    g->AddNode("proc_stmt", this->line(), this->col());
    g->AddIdentifier(id);
    if (expr_list != nullptr) expr_list->Print(g);
    g->Pop();
}

ASTIfStmt::ASTIfStmt(ASTExpr *expr, ASTStmt *stmt,
                     ASTElseClause *else_clause = nullptr)
        : expr(expr), stmt(stmt), else_clause(else_clause) {}

void ASTIfStmt::Print(GraphGenerator *g) {
    g->AddNode("if_stmt", this->line(), this->col());
    expr->Print(g);
    stmt->Print(g);
    if (else_clause != nullptr) else_clause->Print(g);
    g->Pop();
}

ASTElseClause::ASTElseClause(ASTStmt *stmt) : stmt(stmt) {}

void ASTElseClause::Print(GraphGenerator *g) {
    g->AddNode("else_clause", this->line(), this->col());
    stmt->Print(g);
    g->Pop();
}

ASTRepeatStmt::ASTRepeatStmt(ASTStmtList *stmt_list, ASTExpr *expr)
        : stmt_list_(stmt_list), expr_(expr) {}

void ASTRepeatStmt::Print(GraphGenerator *g) {
    g->AddNode("repeat_stmt", line(), col());
    this->stmt_list_->Print(g);
    this->expr_->Print(g);
    g->Pop();
}

ASTWhileStmt::ASTWhileStmt(ASTExpr *expr, ASTStmt *stmt)
        : expr_(expr), stmt_(stmt) {}

void ASTWhileStmt::Print(GraphGenerator *g) {
    g->AddNode("while_stmt", line(), col());
    this->expr_->Print(g);
    this->stmt_->Print(g);
    g->Pop();
}

ASTForStmt::ASTForStmt(std::string id, ASTExpr *for_expr, ForDir dir,
                       ASTExpr *to_expr, ASTStmt *stmt)
        : id_(id), for_expr_(for_expr), dir_(dir), to_expr_(to_expr), stmt_(stmt) {}

void ASTForStmt::Print(GraphGenerator *g) {
    std::string dir_name;
    switch (dir_) {
        case ForDir::TO:
            dir_name = "TO";
            break;
        case ForDir::DOWNTO:
            dir_name = "DOWNTO";
            break;
    }
    g->AddNode(std::string("for_stmt: ") + dir_name, this->line(), this->col());
    g->AddIdentifier(id_);
    this->for_expr_->Print(g);
    this->to_expr_->Print(g);
    this->stmt_->Print(g);
    g->Pop();
}

ASTCaseStmt::ASTCaseStmt(ASTExpr *expr, ASTCaseExprList *case_expr_list)
        : expr_(expr), case_expr_list_(case_expr_list) {}

void ASTCaseStmt::Print(GraphGenerator *g) {
    g->AddNode("case_stmt", this->line(), this->col());
    this->expr_->Print(g);
    this->case_expr_list_->Print(g);
    g->Pop();
}

ASTCaseExprList::ASTCaseExprList() {}

void ASTCaseExprList::add_case_expr(ASTCaseExpr *expr) {
    this->case_expr_list_.push_back(expr);
}

void ASTCaseExprList::Print(GraphGenerator *g) {
    g->AddNode("case_expr_list", this->line(), this->col());
    for (auto expr : case_expr_list_) expr->Print(g);
    g->Pop();
}

ASTCaseExpr::ASTCaseExpr(ASTExpr *expr, ASTStmt *stmt)
        : expr_(expr), stmt_(stmt) {}

void ASTCaseExpr::Print(GraphGenerator *g) {
    g->AddNode("case_expr", this->line(), this->col());
    this->expr_->Print(g);
    this->stmt_->Print(g);
    g->Pop();
}

ASTGotoStmt::ASTGotoStmt(std::string label) : label_(label) {}

void ASTGotoStmt::Print(GraphGenerator *g) {
    std::stringstream ss;
    ss << "goto_stmt: " << label_;
    g->AddNode(ss.str(), this->line(), this->col());
    g->Pop();
}

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

void ASTExitStmt::Print(GraphGenerator *g) {
    g->AddNode("exit", this->line(), this->col());
    if (this->getExpr()) this->getExpr()->Print(g);
    g->Pop();
}

std::shared_ptr<VisitorResult> ASTExitStmt::Accept(Visitor *visitor) {
    return visitor->VisitASTExitStmt(this);
}


void ASTBreakStmt::Print(GraphGenerator *g) {
    g->AddNode("break", this->line(), this->col());
    g->Pop();
}

std::shared_ptr<VisitorResult> ASTBreakStmt::Accept(Visitor *visitor) {
    return visitor->VisitASTBreakStmt(this);
}
