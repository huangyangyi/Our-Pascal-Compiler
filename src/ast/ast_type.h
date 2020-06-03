#ifndef OPC_AST_AST_TYPE_H
#define OPC_AST_AST_TYPE_H

#include "ast_base.h"
#include "ast_value.h"

class Generator;

class Visitor;

class ASTNode;

class ASTType;

class ASTTypeDecl;

class ASTSimpleTypeDecl;

class ASTConstValue;

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
        INTEGER, REAL, BOOLEAN, CHAR, STRING
    };

    ASTType(TypeName type_name);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    TypeName getTypeName() const;

private:
    TypeName type_name;
};

class ASTTypeDecl : public ASTNode {
public:
    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor) { return nullptr; }
};

class ASTSimpleTypeDecl : public ASTTypeDecl {
friend class Generator;
public:
    enum class MyType { BUILTIN_TYPE, DEFINED_ID, VALUE_RANGE, ID_RANGE, ENUM };

    ASTSimpleTypeDecl(ASTType *);  // Now only implement the simple type.
    ASTSimpleTypeDecl(ASTConstValue *low, bool neg_low, ASTConstValue* high, bool neg_high);
    ASTSimpleTypeDecl(std::string low_name, std::string high_name);
    ASTSimpleTypeDecl(std::string defined_id);
    ASTSimpleTypeDecl(ASTNameList *name_list);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTType *getTypeName() const;

    MyType my_type;

private:
    ASTType *type_name;
    std::string defined_id;
public:
    const std::string &getDefinedId() const;

private:
    bool neg_low, neg_high;
    ASTConstValue *low, *high;
    std::string low_name, high_name;
    ASTNameList *name_list;

    friend class Generator;
};

class ASTArrayTypeDecl : public ASTTypeDecl {
public:
    ASTArrayTypeDecl(ASTSimpleTypeDecl *, ASTTypeDecl *);



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



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTNameList *getNameList() const;

    ASTTypeDecl *getTypeDecl() const;

//    void setBelongToRecord(bool _);
private:
    ASTNameList *name_list;
    ASTTypeDecl *type_decl;
    bool belong_to_record = false;
};

class ASTFieldDeclList : public ASTNode {
public:
    ASTFieldDeclList(ASTFieldDecl *);

    void addFieldDecl(ASTFieldDecl *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const std::vector<ASTFieldDecl *> &getFielddeclList() const;

//    void setBelongToRecord(bool _);
//    void getBelongToRecord();
private:
    std::vector<ASTFieldDecl *> fielddeclList;
    bool belong_to_record = false;
};

class ASTRecordTypeDecl : public ASTTypeDecl {
public:
    ASTRecordTypeDecl(ASTFieldDeclList *);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTFieldDeclList *getFieldDeclList() const;

private:
    ASTFieldDeclList *field_decl_list;
};

class ASTTypeDefinition : public ASTNode {
public:
    ASTTypeDefinition(std::string, ASTTypeDecl *);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const std::string &getId() const;

    ASTTypeDecl *getTypeDecl() const;

private:
    std::string id_;
    ASTTypeDecl *type_decl_;
};

class ASTTypeDeclList : public ASTNode {
public:
    ASTTypeDeclList(ASTTypeDefinition *);

    void addASTTypeDefinition(ASTTypeDefinition *);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const std::vector<ASTTypeDefinition *> &getTypeList() const;

private:
    std::vector<ASTTypeDefinition *> typeList;
};

class ASTTypePart : public ASTNode {
public:
    ASTTypePart(ASTTypeDeclList *);


    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTTypeDeclList *getTypeDeclList() const;

private:
    ASTTypeDeclList *type_decl_list_;

};

#endif //OPC_AST_AST_TYPE_H