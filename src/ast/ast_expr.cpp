#include "ast_expr.h"

ASTExpressionList::ASTExpressionList(ASTExpr* expr) {
    expr_list_.push_back(expr);
}

void ASTExpressionList::AddExpr(ASTExpr* expr) { expr_list_.push_back(expr); }

void ASTExpressionList::Print(GraphGenerator* graph) {
    graph->AddNode("expression_list", this->line(), this->col());
    for (auto expr : expr_list_) expr->Print(graph);
    graph->Pop();
}

ASTBinaryExpr::ASTBinaryExpr(ASTBinaryExpr::Oper op, ASTExpr* l_expr,
                             ASTExpr* r_expr)
    : op_(op), l_expr_(l_expr), r_expr_(r_expr) {}

std::string ASTBinaryExpr::_op_name(Oper op_) {
    switch (op_) {
        case Oper::GE:
            return "GE";
            break;
        case Oper::GT:
            return "GT";
            break;
        case Oper::LE:
            return "LE";
            break;
        case Oper::LT:
            return "LT";
            break;
        case Oper::EQUAL:
            return "EQUAL";
            break;
        case Oper::UNEQUAL:
            return "UNEQUAL";
            break;
        case Oper::PLUS:
            return "PLUS";
            break;
        case Oper::MINUS:
            return "MINUS";
            break;
        case Oper::OR:
            return "OR";
            break;
        case Oper::MUL:
            return "MUL";
            break;
        case Oper::DIV:
            return "DIV";
            break;
        case Oper::MOD:
            return "MOD";
            break;
        case Oper::AND:
            return "AND";
            break;
    }
    return "";
}

void ASTBinaryExpr::Print(GraphGenerator* graph) {
    std::string op_name = _op_name(op_);
    graph->AddNode(std::string("binary_op_expr: ") + op_name, this->line(),
                   this->col());
    this->l_expr_->Print(graph);
    this->r_expr_->Print(graph);
    graph->Pop();
}

ASTUnaryExpr::ASTUnaryExpr(ASTUnaryExpr::Oper op, ASTExpr* expr)
    : op_(op), expr_(expr) {}

void ASTUnaryExpr::Print(GraphGenerator* graph) {
    std::string op_name;
    switch (op_) {
        case Oper::NOT:
            op_name = "NOT";
            break;
        case Oper::SUB:
            op_name = "SUB";
            break;
    }
    graph->AddNode(std::string("unary_op_expr: ") + op_name, this->line(),
                   this->col());
    expr_->Print(graph);
    graph->Pop();
}

ASTPropExpr::ASTPropExpr(char* id, char* prop_id)
    : id_(id), prop_id_(prop_id) {}

void ASTPropExpr::Print(GraphGenerator* graph) {
    graph->AddNode("property_expr:", this->line(), this->col());
    graph->AddIdentifier(id_);
    graph->AddIdentifier(prop_id_);
    graph->Pop();
}

ASTConstExpr::ASTConstExpr(ASTConstValue* const_value)
    : const_value_(const_value) {}

void ASTConstExpr::Print(GraphGenerator* graph) { const_value_->Print(graph); }
ASTFuncCall::ASTFuncCall(char* func_id, ASTExpressionList* arg_list)
    : func_id_(func_id), arg_list_(arg_list) {}

void ASTFuncCall::Print(GraphGenerator* graph) {
    graph->AddNode("func_call", this->line(), this->col());
    graph->AddIdentifier(func_id_);
    this->arg_list_->Print(graph);
    graph->Pop();
}