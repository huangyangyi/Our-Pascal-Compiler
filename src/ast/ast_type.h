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

   private:
    TypeName type_name;
};

class ASTTypeDecl : public ASTNode {};

class ASTSimpleTypeDecl : public ASTTypeDecl {
   public:
    ASTSimpleTypeDecl(ASTType);  // Now only implement the simple type.
    virtual void Print(GraphGenerator* g);

   private:
    ASTType* type_name;
};

class ASTArrayTypeDecl : public ASTTypeDecl {
   public:
    ASTArrayTypeDecl(ASTSimpleTypeDecl*, ASTTypeDecl*);
};

class ASTFieldDecl : public ASTNode {
    ASTFieldDecl(ASTNameList*, ASTTypeDecl*);
};

class ASTFieldDeclList : public ASTNode {
   public:
    ASTFieldDeclList(ASTFieldDecl*);
    void addASTFieldDecl(ASTFieldDecl*);

   private:
    std::vector<ASTFieldDecl*> fielddeclList;
};

class ASTRecordTypeDecl : public ASTTypeDecl {
   public:
    ASTRecordTypeDecl(ASTFieldDeclList*);
};

class ASTTypeDefinition : public ASTNode {
   public:
    ASTTypeDefinition(char*, ASTTypeDecl*);
};

class ASTTypeDeclList : public ASTNode {
   public:
    ASTTypeDeclList(ASTTypeDefinition*);
    void addASTTypeDefinition(ASTTypeDefinition*);

   private:
    std::vector<ASTTypeDefinition*> typeList;
};

class ASTTypePart : public ASTNode {
   public:
    ASTTypePart(ASTTypeDeclList*);
};
