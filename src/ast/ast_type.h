#ifndef OPC_AST_AST_TYPE_H
#define OPC_AST_AST_TYPE_H

#include "ast_base.h"

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
    enum class TypeName { INTERGER, REAL, BOOLEAN, CHAR };
    ASTType(TypeName type_name);
    virtual void Print(GraphGenerator *);

   private:
    TypeName type_name;
};

class ASTTypeDecl : public ASTNode {};

class ASTSimpleTypeDecl : public ASTTypeDecl {
   public:
    ASTSimpleTypeDecl(ASTType *);  // Now only implement the simple type.
    virtual void Print(GraphGenerator* g);

   private:
    ASTType* type_name;
};

class ASTArrayTypeDecl : public ASTTypeDecl {
   public:
    ASTArrayTypeDecl(ASTSimpleTypeDecl*, ASTTypeDecl*);
    virtual void Print(GraphGenerator *);
    private:
    ASTSimpleTypeDecl *simple_type_decl;
    ASTTypeDecl *type_decl;
};

class ASTFieldDecl : public ASTNode {
    public:
    ASTFieldDecl(ASTNameList*, ASTTypeDecl*);
    virtual void Print(GraphGenerator *);
    private:
     ASTNameList *name_list;
     ASTTypeDecl *type_decl;
};

class ASTFieldDeclList : public ASTNode {
   public:
    ASTFieldDeclList(ASTFieldDecl*);
    void addFieldDecl(ASTFieldDecl*);
    virtual void Print(GraphGenerator* g);
   private:
    std::vector<ASTFieldDecl*> fielddeclList;
};

class ASTRecordTypeDecl : public ASTTypeDecl {
   public:
    ASTRecordTypeDecl(ASTFieldDeclList*);
    virtual void Print(GraphGenerator *);
    private:
     ASTFieldDeclList *field_decl_list;
};

class ASTTypeDefinition : public ASTNode {
   public:
    ASTTypeDefinition(char*, ASTTypeDecl*);
    virtual void Print(GraphGenerator *);
};

class ASTTypeDeclList : public ASTNode {
   public:
    ASTTypeDeclList(ASTTypeDefinition*);
    void addASTTypeDefinition(ASTTypeDefinition*);
    virtual void Print(GraphGenerator *);

   private:
    std::vector<ASTTypeDefinition*> typeList;
};

class ASTTypePart : public ASTNode {
   public:
    ASTTypePart(ASTTypeDeclList*);
    virtual void Print(GraphGenerator *);
};

#endif //OPC_AST_AST_TYPE_H