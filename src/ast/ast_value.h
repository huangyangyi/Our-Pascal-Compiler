#ifndef OPC_AST_AST_VALUE_H
#define OPC_AST_AST_VALUE_H

#include <vector>

#include "ast_base.h"
#include "ast_type.h"

class ASTConstValue;
class ASTConstExprList;
class ASTConstPart;
class ASTVarPart;
class ASTVarDeclList;
class ASTVarDecl;

class ASTConstValue : public ASTNode {
   public:
    enum class ValueType { INTEGER, FLOAT, CHAR, STRING, BOOL };
    ASTConstValue(std::string, ValueType);
    virtual void Print(GraphGenerator*);

   private:
    ValueType value_type;
    std::string content;
    std::string _value_type_name(ValueType value_type);
};

class ASTConstExprList : public ASTNode {
   public:
    ASTConstExprList(std::string, ASTConstValue*);
    void add_const_expr(std::string, ASTConstValue*);
    virtual void Print(GraphGenerator*);

   private:
    std::vector<std::string> const_id_list;
    std::vector<ASTConstValue*> const_value_list;
};

class ASTConstPart : public ASTNode {
   public:
    ASTConstPart(ASTConstExprList* const_expr_list);
    virtual void Print(GraphGenerator*);

   private:
    ASTConstExprList* const_expr_list;
};

class ASTVarPart : public ASTNode {
   public:
    ASTVarPart(ASTVarDeclList*);
    virtual void Print(GraphGenerator*);

   private:
    ASTVarDeclList* var_decl_list;
};

class ASTVarDeclList : public ASTNode {
   public:
    ASTVarDeclList(ASTVarDecl*);
    virtual void Print(GraphGenerator*);
    void addVarDecl(ASTVarDecl*);

   private:
    std::vector<ASTVarDecl*> var_decl_list;
};

class ASTVarDecl : public ASTNode {
   public:
    ASTVarDecl(ASTNameList*, ASTTypeDecl*);
    virtual void Print(GraphGenerator*);

   private:
    ASTNameList* name_list;
    ASTTypeDecl* type_decl;
};

#endif  // OPC_AST_AST_VALUE_H