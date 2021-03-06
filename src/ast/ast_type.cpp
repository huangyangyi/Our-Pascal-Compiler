#include "ast_type.h"
#include "../visitor.h"
#include "../generator/generator.h"


ASTType::ASTType(TypeName type_name) : type_name(type_name) {}

ASTSimpleTypeDecl::ASTSimpleTypeDecl(ASTType *type) : type_name(type), my_type(MyType::BUILTIN_TYPE) {}

ASTSimpleTypeDecl::ASTSimpleTypeDecl(ASTConstValue *low, bool neg_low, ASTConstValue* high, bool neg_high):
    my_type(MyType::VALUE_RANGE), low(low), neg_low(neg_low), high(high), neg_high(neg_high)
{ }

ASTSimpleTypeDecl::ASTSimpleTypeDecl(std::string low_name, std::string high_name):
    my_type(MyType::ID_RANGE), low_name(low_name), high_name(high_name)
{ }

ASTSimpleTypeDecl::ASTSimpleTypeDecl(std::string defined_id):
    my_type(MyType::DEFINED_ID), defined_id(defined_id) {}

ASTSimpleTypeDecl::ASTSimpleTypeDecl(ASTNameList *name_list): name_list(name_list), my_type{MyType::ENUM} {}


ASTArrayTypeDecl::ASTArrayTypeDecl(ASTSimpleTypeDecl *simple_type_decl,
                                   ASTTypeDecl *type_decl)
        : simple_type_decl(simple_type_decl), type_decl(type_decl) {}

ASTFieldDecl::ASTFieldDecl(ASTNameList *name_list, ASTTypeDecl *type_decl)
        : name_list(name_list), type_decl(type_decl) { }

ASTFieldDeclList::ASTFieldDeclList(ASTFieldDecl *field_decl) {
    fielddeclList.clear();
    fielddeclList.push_back(field_decl);
}

void ASTFieldDeclList::addFieldDecl(ASTFieldDecl *field_decl) {
    fielddeclList.push_back(field_decl);
}

ASTRecordTypeDecl::ASTRecordTypeDecl(ASTFieldDeclList *field_decl_list)
        : field_decl_list(field_decl_list) {}

ASTTypePart::ASTTypePart(ASTTypeDeclList *type_decl_list) : type_decl_list_(type_decl_list) {}

ASTTypeDefinition::ASTTypeDefinition(std::string id, ASTTypeDecl *type_decl) : id_(id), type_decl_(type_decl) {}

ASTTypeDeclList::ASTTypeDeclList(ASTTypeDefinition *defi) {
    this->typeList.push_back(defi);
}

void ASTTypeDeclList::addASTTypeDefinition(ASTTypeDefinition *defi) {
    this->typeList.push_back(defi);
}

std::shared_ptr<VisitorResult> ASTType::Accept(Visitor *visitor) { return visitor->VisitASTType(this); }

ASTType::TypeName ASTType::getTypeName() const {
    return type_name;
}

std::shared_ptr<VisitorResult> ASTSimpleTypeDecl::Accept(Visitor *visitor) {
    return visitor->VisitASTSimpleTypeDecl(this);
}

ASTType *ASTSimpleTypeDecl::getTypeName() const {
    return type_name;
}

const string &ASTSimpleTypeDecl::getDefinedId() const {
    return defined_id;
}

std::shared_ptr<VisitorResult> ASTArrayTypeDecl::Accept(Visitor *visitor) {
    return visitor->VisitASTArrayTypeDecl(this);
}

ASTSimpleTypeDecl *ASTArrayTypeDecl::getSimpleTypeDecl() const {
    return simple_type_decl;
}

ASTTypeDecl *ASTArrayTypeDecl::getTypeDecl() const {
    return type_decl;
}

std::shared_ptr<VisitorResult> ASTFieldDecl::Accept(Visitor *visitor) { return visitor->VisitASTFieldDecl(this); }

ASTNameList *ASTFieldDecl::getNameList() const {
    return name_list;
}

ASTTypeDecl *ASTFieldDecl::getTypeDecl() const {
    return type_decl;
}

std::shared_ptr<VisitorResult> ASTFieldDeclList::Accept(Visitor *visitor) {
    return visitor->VisitASTFieldDeclList(this);
}

const vector<ASTFieldDecl *> &ASTFieldDeclList::getFielddeclList() const {
    return fielddeclList;
}

std::shared_ptr<VisitorResult> ASTRecordTypeDecl::Accept(Visitor *visitor) {
    return visitor->VisitASTRecordTypeDecl(this);
}

ASTFieldDeclList *ASTRecordTypeDecl::getFieldDeclList() const {
    return field_decl_list;
}

std::shared_ptr<VisitorResult> ASTTypeDefinition::Accept(Visitor *visitor) {
    return visitor->VisitASTTypeDefinition(this);
}

const string &ASTTypeDefinition::getId() const {
    return id_;
}

ASTTypeDecl *ASTTypeDefinition::getTypeDecl() const {
    return type_decl_;
}

std::shared_ptr<VisitorResult> ASTTypeDeclList::Accept(Visitor *visitor) { return visitor->VisitASTTypeDeclList(this); }

const vector<ASTTypeDefinition *> &ASTTypeDeclList::getTypeList() const {
    return typeList;
}

std::shared_ptr<VisitorResult> ASTTypePart::Accept(Visitor *visitor) { return visitor->VisitASTTypePart(this); }

ASTTypeDeclList *ASTTypePart::getTypeDeclList() const {
    return type_decl_list_;
}
