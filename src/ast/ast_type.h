#include <ast.h>

class Type_decl: public ASTNode{
    
};

class ASTSimpleTypeDecl: public Type_decl{
    ASTSimpleTypeDecl(ASTType);
};

class ASTArrayTypeDecl: public Type_decl{
public:
    ASTArrayTypeDecl(ASTSimpleTypeDecl, Type_decl);
};

class ASTFieldDecl: public ASTNode{
    ASTFieldDecl(ASTNameList, Type_decl);
};

class ASTFieldDeclList: public ASTNode{
public:
    ASTFieldDeclList(ASTFieldDecl);
    void addASTFieldDecl(ASTFieldDecl);
private:
    std::vector<ASTFieldDecl*> fielddeclList;
};

class ASTRecordTypeDecl: public Type_decl{
public:
    ASTRecordTypeDecl(ASTFieldDeclList);
};

class ASTTypeDefinition : public ASTNode {
public:
    ASTTypeDefinition(char*, ASTTypeDec);
};

class ASTTypeDeclList : public ASTNode {
public:
    ASTTypeDeclList(ASTTypeDefinition);
    void addASTTypeDefinition(ASTTypeDefinition);
private:
    std::vector<ASTTypeDefinition*> typeList;
};

class ASTTypePart: public ASTNode{
public:
    ASTTypePart(ASTTypeDeclList);
}

class ASTVarDecl: public ASTNode{
public:
    VarDecl(ASTNameList, ASTTypeDecl);
}

class ASTVarDeclList: public ASTNode{
public:
    ASTVarDeclList(ASTVarDecl);
    void addASTVarDecl(ASTVarDecl);
private:
    std::vector<ASTVarDecl*> vardeclList;
}

class ASTVarPart: public {
public:
    void ASTVarDeclList(ASTVarPart);
}
