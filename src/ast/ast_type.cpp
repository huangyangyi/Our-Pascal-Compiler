#include "ast_type.h"

ASTType::ASTType(TypeName type_name) : type_name(type_name) {}
void ASTType::Print(GraphGenerator* g) {
    // Need to be considered more...
    switch (type_name) {
        case TypeName::INTERGER:
            g->AddIdentifier("Integer");
            break;
        case TypeName::REAL:
            g->AddIdentifier("Real");
            break;
        case TypeName::BOOLEAN:
            g->AddIdentifier("Boolean");
            break;
        case TypeName::CHAR:
            g->AddIdentifier("Char");
            break;
    }
}

ASTSimpleTypeDecl::ASTSimpleTypeDecl(ASTType *type) : type_name(type) {}

void ASTSimpleTypeDecl::Print(GraphGenerator* g) {
    g->AddNode("simple_type_decl", this->line(), this->col());
    type_name->Print(g);
    g->Pop();
}

ASTArrayTypeDecl::ASTArrayTypeDecl(ASTSimpleTypeDecl* simple_type_decl,
                                   ASTTypeDecl* type_decl)
    : simple_type_decl(simple_type_decl), type_decl(type_decl) {}
void ASTArrayTypeDecl::Print(GraphGenerator* g) {
    g->AddNode("array_type_decl", this->line(), this->col());
    simple_type_decl->Print(g);
    type_decl->Print(g);
    g->Pop();
}

ASTFieldDecl::ASTFieldDecl(ASTNameList* name_list, ASTTypeDecl* type_decl)
    : name_list(name_list), type_decl(type_decl) {}
void ASTFieldDecl::Print(GraphGenerator* g) {
    g->AddNode("field_decl", this->line(), this->col());
    name_list->Print(g);
    type_decl->Print(g);
    g->Pop();
}

ASTFieldDeclList::ASTFieldDeclList(ASTFieldDecl* field_decl) {
    fielddeclList.clear();
    fielddeclList.push_back(field_decl);
}
void ASTFieldDeclList::addFieldDecl(ASTFieldDecl* field_decl) {
    fielddeclList.push_back(field_decl);
}
void ASTFieldDeclList::Print(GraphGenerator* g) {
    g->AddNode("field_decl_list", this->line(), this->col());
    for (int i = 0; i < (int)fielddeclList.size(); i++)
        fielddeclList[i]->Print(g);
    g->Pop();
}

ASTRecordTypeDecl::ASTRecordTypeDecl(ASTFieldDeclList* field_decl_list)
    : field_decl_list(field_decl_list) {}

void ASTRecordTypeDecl::Print(GraphGenerator* g) {
    g->AddNode("file_decl_list", this->line(), this->col());
    field_decl_list->Print(g);
    g->Pop();
}

ASTTypePart::ASTTypePart(ASTTypeDeclList *type_decl_list):type_decl_list_(type_decl_list){}

void ASTTypePart::Print(GraphGenerator *g) {
    g->AddNode("type_part", this->line(), this->col());
    this->type_decl_list_->Print(g);
    g->Pop();
}

ASTTypeDefinition::ASTTypeDefinition(std::string id , ASTTypeDecl* type_decl):id_(id), type_decl_(type_decl){}

void ASTTypeDefinition::Print(GraphGenerator *g) {
    g->AddNode("type_definition", this->line(), this->col());
    g->AddIdentifier(this->id_);
    this->type_decl_->Print(g);
    g->Pop();
}

ASTTypeDeclList::ASTTypeDeclList(ASTTypeDefinition* defi) {
    this->typeList.push_back(defi);
}

void ASTTypeDeclList::addASTTypeDefinition(ASTTypeDefinition* defi) {
    this->typeList.push_back(defi);
}

void ASTTypeDeclList::Print(GraphGenerator *g) {
    g->AddNode("type_decl_list", line(), col());
    for (auto defi: this->typeList){
        defi->Print(g);
    }
    g->Pop();
}

void ASTType::Accept(Visitor* visitor){ return visitor->VisitASTType(this); }

void ASTSimpleTypeDecl::Accept(Visitor* visitor){ return visitor->VisitASTSimpleTypeDecl(this); }

void ASTArrayTypeDecl::Accept(Visitor* visitor){ return visitor->VisitASTArrayTypeDecl(this); }

void ASTFieldDecl::Accept(Visitor* visitor){ return visitor->VisitASTFieldDecl(this); }

void ASTFieldDeclList::Accept(Visitor* visitor){ return visitor->VisitASTFieldDeclList(this); }

void ASTRecordTypeDecl::Accept(Visitor* visitor){ return visitor->VisitASTRecordTypeDecl(this); }

void ASTTypeDefinition::Accept(Visitor* visitor){ return visitor->VisitASTTypeDefinition(this); }

void ASTTypeDeclList::Accept(Visitor* visitor){ return visitor->VisitASTTypeDeclList(this); }

void ASTTypePart::Accept(Visitor* visitor){ return visitor->VisitASTTypePart(this); }