#include "ast_stmt.h"

#include <sstream>

ASTStmtList::ASTStmtList(ASTStmt *stmt) {
    stmt_list.clear();
    stmt_list.push_back(stmt);
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
    : expr1(expr1), expr2(expr2){};
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

ASTGotoStmt::ASTGotoStmt(std::string label):label_(label) {} 

void ASTGotoStmt::Print(GraphGenerator *g) {
    std::stringstream ss;
    ss << "goto_stmt: " << label_;
    g->AddNode(ss.str(), this->line(), this->col());
    g->Pop();
}

void ASTStmt::Accept(Visitor* visitor){ return visitor->VisitASTStmt(this); }

void ASTStmtList::Accept(Visitor* visitor){ return visitor->VisitASTStmtList(this); }

void ASTAssignStmt::Accept(Visitor* visitor){ return visitor->VisitASTAssignStmt(this); }

void ASTProcStmt::Accept(Visitor* visitor){ return visitor->VisitASTProcStmt(this); }

void ASTIfStmt::Accept(Visitor* visitor){ return visitor->VisitASTIfStmt(this); }

void ASTElseClause::Accept(Visitor* visitor){ return visitor->VisitASTElseClause(this); }

void ASTRepeatStmt::Accept(Visitor* visitor){ return visitor->VisitASTRepeatStmt(this); }

void ASTWhileStmt::Accept(Visitor* visitor){ return visitor->VisitASTWhileStmt(this); }

void ASTForStmt::Accept(Visitor* visitor){ return visitor->VisitASTForStmt(this); }

void ASTCaseStmt::Accept(Visitor* visitor){ return visitor->VisitASTCaseStmt(this); }

void ASTCaseExprList::Accept(Visitor* visitor){ return visitor->VisitASTCaseExprList(this); }

void ASTCaseExpr::Accept(Visitor* visitor){ return visitor->VisitASTCaseExpr(this); }

void ASTGotoStmt::Accept(Visitor* visitor){ return visitor->VisitASTGotoStmt(this); }
