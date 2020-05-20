#include <vector>
#include "ast_expr.h"
enum ValueType { INT, FLOAT, BOOL, STRING, CHAR };

class ASTNode {
private:
    int x, y;

public:
    ASTNode();
    void set_location(int x, int y);
    virtual void print() const = 0;
};

class ASTTypeDecl {};

class ASTSimpleTypeDecl : public ASTTypeDecl {};

class ASTArrayTypeDecl : public ASTTypeDecl {};

class ASTRecordTypeDecl : public ASTTypeDecl {};

class ASTType : public ASTNode {
public:
    enum class TypeName {
        INTERGER,
        REAL,
        BOOLEAN,
        CHAR
    };
    ASTType(TypeName type_name);
};

class ASTNameList: public ASTNode{
public:
    void addIDENTIFIER(IDENTIFIER);
private:
    std::vector<*IDENTIFIER> identifierList;
};

