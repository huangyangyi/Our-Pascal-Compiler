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

ASTConstExprList::ASTConstExprList(std::string id, ASTConstValue* const_value) {
    const_id_list.clear();
    const_value_list.clear();
    const_id_list.push_back(id);
    const_value_list.push_back(const_value);
}
void ASTConstExprList::add_const_expr(std::string id,
                                      ASTConstValue* const_value) {
    const_id_list.push_back(id);
    const_value_list.push_back(const_value);
}
void ASTConstExprList::Print(GraphGenerator* g) {
    g->AddNode("const_expr_list", this->line(), this->col());
    assert(const_id_list.size() == const_value_list.size());
    for (int i = 0; i < const_id_list.size(); i++) {
        g->AddIdentifier(const_id_list[i]);
        const_value_list[i]->Print(g);
    }
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
