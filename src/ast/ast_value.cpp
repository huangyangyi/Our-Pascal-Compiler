#include "ast_value.h"
#include "../visitor.h"

#include <iostream>

ASTConstValue::ASTConstValue(std::string content,
                             ASTConstValue::ValueType value_type)
        : content(content), value_type(value_type) {}

std::string ASTConstValue::getValueTypeName(
        ASTConstValue::ValueType value_type) {
    std::string name;
    switch (value_type) {
        case ValueType::INTEGER:
            name = "INTEGER";
            break;
        case ValueType::FLOAT:
            name = "FLOAT";
            break;
        case ValueType::CHAR:
            name = "CHAR";
            break;
        case ValueType::STRING:
            name = "STRING";
            break;
        case ValueType::BOOL:
            name = "BOOL";
            break;
    }
    return name;
}

ASTConstPart::ASTConstPart(ASTConstExprList *const_expr_list)
        : const_expr_list(const_expr_list) {}

ASTConstExprList::ASTConstExprList() = default;

void ASTConstExprList::add_const_expr(ASTConstExpr *const_expr) {
    const_expr_list.push_back(const_expr);
}

ASTConstExpr::ASTConstExpr(std::string id, ASTExpr *value) : id(id), value(value) {}

ASTVarPart::ASTVarPart(ASTVarDeclList *var_decl_list)
        : var_decl_list(var_decl_list) {}

ASTVarDeclList::ASTVarDeclList(ASTVarDecl *var_decl) {
    var_decl_list.clear();
    var_decl_list.push_back(var_decl);
}

void ASTVarDeclList::addVarDecl(ASTVarDecl *var_decl) {
    var_decl_list.push_back(var_decl);
}

ASTVarDecl::ASTVarDecl(ASTNameList *name_list, ASTTypeDecl *type_decl)
        : name_list(name_list), type_decl(type_decl) {}

std::shared_ptr<VisitorResult> ASTConstValue::Accept(Visitor *visitor) { return visitor->VisitASTConstValue(this); }

ASTConstValue::ValueType ASTConstValue::getValueType() const {
    return value_type;
}

const string &ASTConstValue::getContent() const {
    return content;
}

std::shared_ptr<VisitorResult> ASTConstExprList::Accept(Visitor *visitor) {
    return visitor->VisitASTConstExprList(this);
}

const vector<ASTConstExpr *> &ASTConstExprList::getConstExprList() const {
    return const_expr_list;
}

std::shared_ptr<VisitorResult> ASTConstExpr::Accept(Visitor *visitor) { return visitor->VisitASTConstExpr(this); }

const string &ASTConstExpr::getId() const {
    return id;
}

ASTExpr *ASTConstExpr::getValue() const {
    return value;
}

std::shared_ptr<VisitorResult> ASTConstPart::Accept(Visitor *visitor) { return visitor->VisitASTConstPart(this); }

ASTConstExprList *ASTConstPart::getConstExprList() const {
    return const_expr_list;
}

std::shared_ptr<VisitorResult> ASTVarPart::Accept(Visitor *visitor) { return visitor->VisitASTVarPart(this); }

ASTVarDeclList *ASTVarPart::getVarDeclList() const {
    return var_decl_list;
}

std::shared_ptr<VisitorResult> ASTVarDeclList::Accept(Visitor *visitor) { return visitor->VisitASTVarDeclList(this); }

const vector<ASTVarDecl *> &ASTVarDeclList::getVarDeclList() const {
    return var_decl_list;
}

std::shared_ptr<VisitorResult> ASTVarDecl::Accept(Visitor *visitor) { return visitor->VisitASTVarDecl(this); }

ASTNameList *ASTVarDecl::getNameList() const {
    return name_list;
}

ASTTypeDecl *ASTVarDecl::getTypeDecl() const {
    return type_decl;
}
