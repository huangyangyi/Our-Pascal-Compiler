#ifndef OPC_AST_AST_TYPE_H
#define OPC_AST_AST_TYPE_H

#include "ast_base.h"

class Visitor;

class ASTNode;

class ASTType;

class ASTTypeDecl;

class ASTSimpleTypeDecl;

class ASTArrayTypeDecl;

class ASTFieldDecl;

class ASTFieldDeclList;

class ASTRecordTypeDecl;

class ASTTypeDefinition;

class ASTTypeDeclList;

class ASTTypePart;

class ASTType : public ASTNode {
public:
    enum class TypeName {
        INTERGER, REAL, BOOLEAN, CHAR
    };

    ASTType(TypeName type_name);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    TypeName getTypeName() const;

private:
    TypeName type_name;
};

class ASTTypeDecl : public ASTNode {
};

class ASTSimpleTypeDecl : public ASTTypeDecl {
public:
    ASTSimpleTypeDecl(ASTType *);  // Now only implement the simple type.
    virtual void Print(GraphGenerator *g);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTType *getTypeName() const;

private:
    ASTType *type_name;
};

class ASTArrayTypeDecl : public ASTTypeDecl {
public:
    ASTArrayTypeDecl(ASTSimpleTypeDecl *, ASTTypeDecl *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTSimpleTypeDecl *getSimpleTypeDecl() const;

    ASTTypeDecl *getTypeDecl() const;

private:
    ASTSimpleTypeDecl *simple_type_decl;
    ASTTypeDecl *type_decl;
};

class ASTFieldDecl : public ASTNode {
public:
    ASTFieldDecl(ASTNameList *, ASTTypeDecl *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTNameList *getNameList() const;

    ASTTypeDecl *getTypeDecl() const;

private:
    ASTNameList *name_list;
    ASTTypeDecl *type_decl;
};

class ASTFieldDeclList : public ASTNode {
public:
    ASTFieldDeclList(ASTFieldDecl *);

    void addFieldDecl(ASTFieldDecl *);

    virtual void Print(GraphGenerator *g);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const vector<ASTFieldDecl *> &getFielddeclList() const;

private:
    std::vector<ASTFieldDecl *> fielddeclList;
};

class ASTRecordTypeDecl : public ASTTypeDecl {
public:
    ASTRecordTypeDecl(ASTFieldDeclList *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTFieldDeclList *getFieldDeclList() const;

private:
    ASTFieldDeclList *field_decl_list;
};

class ASTTypeDefinition : public ASTNode {
public:
    ASTTypeDefinition(std::string, ASTTypeDecl *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const string &getId() const;

    ASTTypeDecl *getTypeDecl() const;

private:
    std::string id_;
    ASTTypeDecl *type_decl_;
};

class ASTTypeDeclList : public ASTNode {
public:
    ASTTypeDeclList(ASTTypeDefinition *);

    void addASTTypeDefinition(ASTTypeDefinition *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const vector<ASTTypeDefinition *> &getTypeList() const;

private:
    std::vector<ASTTypeDefinition *> typeList;
};

class ASTTypePart : public ASTNode {
public:
    ASTTypePart(ASTTypeDeclList *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTTypeDeclList *getTypeDeclList() const;

private:
    ASTTypeDeclList *type_decl_list_;

};

#endif //OPC_AST_AST_TYPE_H