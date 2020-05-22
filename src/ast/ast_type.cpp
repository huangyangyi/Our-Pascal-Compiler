#include "ast_type.h"

ASTType::ASTType(TypeName type_name): type_name(type_name){}
void ASTType::Print(GraphGenerator* g){
    g->AddIdentifier(type_name);  //Need to be considered more...
}

ASTSimpleTypeDecl::ASTSimpleTypeDecl(ASTType type): type(type){}
void ASTSimpleTypeDecl::Print(GraphGenerator* g){
    g->AddNode("simple_type_decl", this->line(), this->col());
    type->Print(g);
    g->Pop();
}

ASTArrayTypeDecl::ASTArrayTypeDecl(ASTSimpleTypeDecl* simple_type_decl, ASTTypeDecl* type_decl)
    : simple_type_decl(simple_type_decl), type_decl(type_decl){}
void ASTArrayTypeDecl::Print(GraphGenerator* g){
    g->AddNode("array_type_decl", this->line(), this->col());
    simple_type_decl->Print(g);
    type_decl->Print(g);
    g->Pop();
}

ASTFieldDecl::ASTFieldDecl(ASTNameList* name_list, ASTTypeDecl* type_decl): name_list(name_list), type_decl(type_decl){}
void ASTFieldDecl::Print(GraphGenerator* g){
    g->AddNode("field_decl", this->line(), this->col());
    name_list->Print(g);
    type_list->Print(g);
    g->Pop();
}

ASTFieldDeclList::ASTFieldDeclList(ASTFieldDecl* field_decl){
    fielddeclList.clear();
    fielddeclList.push_back(field_decl);
}
void ASTFieldDeclList::addFieldDecl(ASTFieldDecl* field_decl){
    fielddeclList.push_back(field_decl);
}
void ASTFieldDeclList::Print(GraphGenerator* g){
    g->AddNode("field_decl_list", this->line(), this->col());
    for (int i = 0; i < (int)fielddeclList.size(); i++)
        fielddeclList[i]->Print(g);
    g->Pop();
}

ASTRecordTypeDecl::ASTRecordTypeDecl(ASTFieldDeclList* field_decl_list): field_decl_list(field_decl_list);
    : field_decl_list(field_decl_list){}
void ASTRecordTypeDecl::Print(GraphGenerator* g){
    g->AddNode("file_decl_list", this->line(), this->col());
    field_decl_list->Print(g);
    g->Pop();
}