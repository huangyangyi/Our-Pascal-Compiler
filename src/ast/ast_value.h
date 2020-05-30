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

class ASTTypeDecl;

class ASTVarDecl;

class ASTConstValue : public ASTNode {
public:
    enum class ValueType {
        INTEGER, FLOAT, CHAR, STRING, BOOL
    };

    ASTConstValue(std::string, ValueType);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ValueType getValueType() const;

    const std::string &getContent() const;

private:
    ValueType value_type;
    std::string content;

    std::string _value_type_name(ValueType value_type);
};

class ASTConstExprList : public ASTNode {
public:
    ASTConstExprList();

    void add_const_expr(ASTConstExpr *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

private:
    std::vector<ASTConstExpr *> const_expr_list;
public:
    const std::vector<ASTConstExpr *> &getConstExprList() const;
};

class ASTConstExpr : public ASTNode {
public:
    ASTConstExpr(std::string, ASTExpr *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const std::string &getId() const;

    ASTExpr *getValue() const;

private:
    std::string id;
    ASTExpr *value;
};

class ASTConstPart : public ASTNode {
public:
    ASTConstPart(ASTConstExprList *const_expr_list);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTConstExprList *getConstExprList() const;

private:
    ASTConstExprList *const_expr_list;
};

class ASTVarPart : public ASTNode {
public:
    ASTVarPart(ASTVarDeclList *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTVarDeclList *getVarDeclList() const;

private:
    ASTVarDeclList *var_decl_list;
};

class ASTVarDeclList : public ASTNode {
public:
    ASTVarDeclList(ASTVarDecl *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    void addVarDecl(ASTVarDecl *);

    const std::vector<ASTVarDecl *> &getVarDeclList() const;

private:
    std::vector<ASTVarDecl *> var_decl_list;
};

class ASTVarDecl : public ASTNode {
public:
    ASTVarDecl(ASTNameList *, ASTTypeDecl *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTNameList *getNameList() const;

    ASTTypeDecl *getTypeDecl() const;

private:
    ASTNameList *name_list;
    ASTTypeDecl *type_decl;
};

#endif  // OPC_AST_AST_VALUE_H