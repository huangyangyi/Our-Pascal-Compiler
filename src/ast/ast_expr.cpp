#include "ast_expr.h"
#include "../visitor.h"


ASTExpressionList::ASTExpressionList(ASTExpr *expr) {
    expr_list_.push_back(expr);
}

void ASTExpressionList::AddExpr(ASTExpr *expr) { expr_list_.push_back(expr); }

ASTBinaryExpr::ASTBinaryExpr(ASTBinaryExpr::Oper op, ASTExpr *l_expr,
                             ASTExpr *r_expr)
        : op_(op), l_expr_(l_expr), r_expr_(r_expr) {}

std::string ASTBinaryExpr::getOpName(Oper op_) {
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
        case Oper::REALDIV:
            return "REALDIV";
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

ASTUnaryExpr::ASTUnaryExpr(ASTUnaryExpr::Oper op, ASTExpr *expr)
        : op_(op), expr_(expr) {}

ASTPropExpr::ASTPropExpr(std::string id, std::string prop_id)
        : id_(id), prop_id_(prop_id) {}

ASTConstValueExpr::ASTConstValueExpr(ASTConstValue *const_value)
        : const_value_(const_value) {}

ASTFuncCall::ASTFuncCall(std::string func_id, ASTExpressionList *arg_list)
        : func_id_(func_id), arg_list_(arg_list) {}

ASTIDExpr::ASTIDExpr(std::string id) : id_(id) {}

ASTArrayExpr::ASTArrayExpr(std::string id, ASTExpr *expr)
        : id_(id), expr_(expr) {}

std::shared_ptr<VisitorResult> ASTExpressionList::Accept(Visitor *visitor) {
    return visitor->VisitASTExpressionList(this);
}

const vector<ASTExpr *> &ASTExpressionList::getExprList() const {
    return expr_list_;
}

std::shared_ptr<VisitorResult> ASTBinaryExpr::Accept(Visitor *visitor) { return visitor->VisitASTBinaryExpr(this); }

ASTBinaryExpr::Oper ASTBinaryExpr::getOp() const {
    return op_;
}

ASTExpr *ASTBinaryExpr::getLExpr() const {
    return l_expr_;
}

ASTExpr *ASTBinaryExpr::getRExpr() const {
    return r_expr_;
}

std::shared_ptr<VisitorResult> ASTUnaryExpr::Accept(Visitor *visitor) { return visitor->VisitASTUnaryExpr(this); }

ASTUnaryExpr::Oper ASTUnaryExpr::getOp() const {
    return op_;
}

ASTExpr *ASTUnaryExpr::getExpr() const {
    return expr_;
}

std::shared_ptr<VisitorResult> ASTPropExpr::Accept(Visitor *visitor) { return visitor->VisitASTPropExpr(this); }

const string &ASTPropExpr::getId() const {
    return id_;
}

const string &ASTPropExpr::getPropId() const {
    return prop_id_;
}

std::shared_ptr<VisitorResult> ASTConstValueExpr::Accept(Visitor *visitor) {
    return visitor->VisitASTConstValueExpr(this);
}

ASTConstValue *ASTConstValueExpr::getConstValue() const {
    return const_value_;
}

std::shared_ptr<VisitorResult> ASTFuncCall::Accept(Visitor *visitor) { return visitor->VisitASTFuncCall(this); }

const string &ASTFuncCall::getFuncId() const {
    return func_id_;
}

ASTExpressionList *ASTFuncCall::getArgList() const {
    return arg_list_;
}

std::shared_ptr<VisitorResult> ASTIDExpr::Accept(Visitor *visitor) { return visitor->VisitASTIDExpr(this); }

const string &ASTIDExpr::getId() const {
    return id_;
}

std::shared_ptr<VisitorResult> ASTArrayExpr::Accept(Visitor *visitor) { return visitor->VisitASTArrayExpr(this); }

const string &ASTArrayExpr::getId() const {
    return id_;
}

ASTExpr *ASTArrayExpr::getExpr() const {
    return expr_;
}
