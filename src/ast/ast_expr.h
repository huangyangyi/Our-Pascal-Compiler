#ifndef OPC_AST_AST_EXPR_H
#define OPC_AST_AST_EXPR_H

#include "ast_base.h"
#include "ast_value.h"

class Visitor;

class ASTNode;

class ASTExpr;

class ASTExpressionList;

class ASTBinaryExpr;

class ASTConstValueExpr;

class ASTIDExpr;

class ASTArrayExpr;

class ASTConstValue;

class ASTExpr : public ASTNode {
};

class ASTExpressionList : public ASTExpr {
public:
    ASTExpressionList(ASTExpr *expr);

    void AddExpr(ASTExpr *expr);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

private:
    std::vector<ASTExpr *> expr_list_;
public:
    const std::vector<ASTExpr *> &getExprList() const;
};

class ASTBinaryExpr : public ASTExpr {
public:
    enum class Oper {
        GE,
        GT,
        LE,
        LT,
        EQUAL,
        UNEQUAL,
        PLUS,
        MINUS,
        OR,
        MUL,
        REALDIV,
        DIV,
        MOD,
        AND
    };

private:
public:
    ASTExpr *getLExpr() const;

    ASTExpr *getRExpr() const;

public:
    Oper getOp() const;
    static std::string getOpName(Oper op_);

private:
    Oper op_;
    ASTExpr *l_expr_, *r_expr_;


public:
    ASTBinaryExpr(Oper op, ASTExpr *l_expr, ASTExpr *r_expr);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);
};

class ASTUnaryExpr : public ASTExpr {
public:

    ASTExpr *getExpr() const;

    enum class Oper {
        NOT, SUB
    };
    Oper getOp() const;

private:
    Oper op_;
    ASTExpr *expr_;

public:
    ASTUnaryExpr(Oper, ASTExpr *);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);
};

class ASTPropExpr : public ASTExpr {
private:
    std::string id_, prop_id_;
public:
    const std::string &getId() const;

    const std::string &getPropId() const;

public:
    ASTPropExpr(std::string id, std::string prop_id);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);
};

class ASTConstValueExpr : public ASTExpr {
private:
    ASTConstValue *const_value_;

public:
    ASTConstValueExpr(ASTConstValue *);



    ASTConstValue *getConstValue() const;

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);
};

class ASTFuncCall : public ASTExpr {
private:
public:
    const std::string &getFuncId() const;

    ASTExpressionList *getArgList() const;

private:
    std::string func_id_;
    ASTExpressionList *arg_list_;

public:
    ASTFuncCall(std::string func_id, ASTExpressionList *arg_list);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);
};

class ASTIDExpr : public ASTExpr {
private:
    std::string id_;

public:
    ASTIDExpr(std::string id);



    const std::string &getId() const;

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);
};

class ASTArrayExpr : public ASTExpr {
private:
    std::string id_;
    ASTExpr *expr_;

public:
    ASTArrayExpr(std::string id, ASTExpr *expr);



    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const std::string &getId() const;

    ASTExpr *getExpr() const;
};

#endif  // OPC_AST_AST_EXPR_H