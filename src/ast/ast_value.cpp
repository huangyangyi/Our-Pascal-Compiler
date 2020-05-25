#include "ast_value.h"

ASTConstValue::ASTConstValue(std::string content,
                             ASTConstValue::ValueType value_type)
    : content(content), value_type(value_type) {}
void ASTConstValue::Print(GraphGenerator* g) {
    std::string value_type_name = _value_type_name(value_type);
    g->AddValue(value_type_name, content);
}

std::string ASTConstValue::_value_type_name(
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

ASTConstPart::ASTConstPart(ASTConstExprList* const_expr_list)
    : const_expr_list(const_expr_list) {}
void ASTConstPart::Print(GraphGenerator* g) {
    g->AddNode("const_part", this->line(), this->col());
    const_expr_list->Print(g);
    g->Pop();
}

ASTConstExprList::ASTConstExprList() = default;

void ASTConstExprList::add_const_expr(ASTConstExpr* const_expr) {
    const_expr_list.push_back(const_expr);
}
void ASTConstExprList::Print(GraphGenerator* g) {
    g->AddNode("const_expr_list", this->line(), this->col());
    for (auto expr: const_expr_list) expr->Print(g);
    g->Pop();
}

ASTConstExpr::ASTConstExpr(std::string id, ASTExpr* value):id(id), value(value){}

void ASTConstExpr::Print(GraphGenerator* g) {
    g->AddNode("const_expr", this->line(), this->col());
    g->AddIdentifier(this->id);
    this->value->Print(g);
    g->Pop();
}

ASTVarPart::ASTVarPart(ASTVarDeclList* var_decl_list)
    : var_decl_list(var_decl_list) {}
void ASTVarPart::Print(GraphGenerator* g) {
    g->AddNode("var_part:", this->line(), this->col());
    var_decl_list->Print(g);
    g->Pop();
}

ASTVarDeclList::ASTVarDeclList(ASTVarDecl* var_decl) {
    var_decl_list.clear();
    var_decl_list.push_back(var_decl);
}

void ASTVarDeclList::addVarDecl(ASTVarDecl* var_decl) {
    var_decl_list.push_back(var_decl);
}

void ASTVarDeclList::Print(GraphGenerator* g) {
    g->AddNode("var_decl_list:", this->line(), this->col());
    for (int i = 0; i < (int)var_decl_list.size(); i++)
        var_decl_list[i]->Print(g);
    g->Pop();
}

ASTVarDecl::ASTVarDecl(ASTNameList* name_list, ASTTypeDecl* type_decl)
    : name_list(name_list), type_decl(type_decl) {}

void ASTVarDecl::Print(GraphGenerator* g) {
    g->AddNode("Var_decl:", this->line(), this->col());
    name_list->Print(g);
    type_decl->Print(g);
    g->Pop();
}

std::shared_ptr<VisitorResult> ASTConstValue::Accept(Visitor* visitor){ return visitor->VisitASTConstValue(this); }

std::shared_ptr<VisitorResult> ASTConstExprList::Accept(Visitor* visitor){ return visitor->VisitASTConstExprList(this); }

std::shared_ptr<VisitorResult> ASTConstExpr::Accept(Visitor* visitor){ return visitor->VisitASTConstExpr(this); }

std::shared_ptr<VisitorResult> ASTConstPart::Accept(Visitor* visitor){ return visitor->VisitASTConstPart(this); }

std::shared_ptr<VisitorResult> ASTVarPart::Accept(Visitor* visitor){ return visitor->VisitASTVarPart(this); }

std::shared_ptr<VisitorResult> ASTVarDeclList::Accept(Visitor* visitor){ return visitor->VisitASTVarDeclList(this); }

std::shared_ptr<VisitorResult> ASTVarDecl::Accept(Visitor* visitor){ return visitor->VisitASTVarDecl(this); }
