#ifndef OPC_AST_AST_VALUE_H
#define OPC_AST_AST_VALUE_H

#include <vector>

#include "ast_base.h"
#include "ast_type.h"
#include "ast_expr.h"

class Visitor;
class ASTNode;

class ASTExpr;
class ASTConstValue;
class ASTConstExprList;
class ASTConstExpr;
class ASTConstPart;
class ASTVarPart;
class ASTVarDeclList;
class ASTVarDecl;

class ASTConstValue : public ASTNode {
   public:
    enum class ValueType { INTEGER, FLOAT, CHAR, STRING, BOOL };
    ASTConstValue(std::string, ValueType);
    virtual void Print(GraphGenerator*);
    virtual void Accept(Visitor *visitor);

   private:
    ValueType value_type;
    std::string content;
    std::string _value_type_name(ValueType value_type);
};

class ASTConstExprList : public ASTNode {
   public:
    ASTConstExprList();
    void add_const_expr(ASTConstExpr *);
    virtual void Print(GraphGenerator*);
    virtual void Accept(Visitor *visitor);

   private:
    std::vector<ASTConstExpr*> const_expr_list;
};

class ASTConstExpr : public ASTNode {
    public:
        ASTConstExpr(std::string, ASTExpr*);
        virtual void Print(GraphGenerator*);
        virtual void Accept(Visitor *visitor);
    private:
        std::string id;
        ASTExpr* value;
};

class ASTConstPart : public ASTNode {
   public:
    ASTConstPart(ASTConstExprList* const_expr_list);
    virtual void Print(GraphGenerator*);
    virtual void Accept(Visitor *visitor);

   private:
    ASTConstExprList* const_expr_list;
};

class ASTVarPart : public ASTNode {
   public:
    ASTVarPart(ASTVarDeclList*);
    virtual void Print(GraphGenerator*);
    virtual void Accept(Visitor *visitor);

   private:
    ASTVarDeclList* var_decl_list;
};

class ASTVarDeclList : public ASTNode {
   public:
    ASTVarDeclList(ASTVarDecl*);
    virtual void Print(GraphGenerator*);
    virtual void Accept(Visitor *visitor);
    void addVarDecl(ASTVarDecl*);

   private:
    std::vector<ASTVarDecl*> var_decl_list;
};

class ASTVarDecl : public ASTNode {
   public:
    ASTVarDecl(ASTNameList*, ASTTypeDecl*);
    virtual void Print(GraphGenerator*);
    virtual void Accept(Visitor *visitor);

   private:
    ASTNameList* name_list;
    ASTTypeDecl* type_decl;
};

#endif  // OPC_AST_AST_VALUE_H