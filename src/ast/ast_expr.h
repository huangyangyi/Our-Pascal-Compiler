#ifndef OPC_AST_AST_EXPR_H
#define OPC_AST_AST_EXPR_H

#include "ast_base.h"
#include "ast_value.h"

class ASTExpr;
class ASTExpressionList;
class ASTBinaryExpr;
class ASTConstValueExpr;
class ASTIDExpr;

class ASTExpr : public ASTNode {};

class ASTExpressionList : public ASTExpr {
   public:
    ASTExpressionList(ASTExpr* expr);
    void AddExpr(ASTExpr* expr);

   private:
    std::vector<ASTExpr*> expr_list_;
    virtual void Print(GraphGenerator*);
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
        DIV,
        MOD,
        AND
    };

   private:
    Oper op_;
    ASTExpr *l_expr_, *r_expr_;
    static std::string _op_name(Oper op_);

   public:
    ASTBinaryExpr(Oper op, ASTExpr* l_expr, ASTExpr* r_expr);
    virtual void Print(GraphGenerator*);
};

class ASTUnaryExpr : public ASTExpr {
   public:
    enum class Oper { NOT, SUB };

   private:
    Oper op_;
    ASTExpr* expr_;

   public:
    ASTUnaryExpr(Oper, ASTExpr*);
    virtual void Print(GraphGenerator*);
};

class ASTPropExpr : public ASTExpr {
   private:
    char *id_, *prop_id_;

   public:
    ASTPropExpr(char* id, char* prop_id);
    virtual void Print(GraphGenerator*);
};

class ASTConstValueExpr : public ASTExpr {
   private:
    ASTConstValue* const_value_;

   public:
    ASTConstValueExpr(ASTConstValue*);
    virtual void Print(GraphGenerator*);
};

class ASTFuncCall : public ASTExpr {
   private:
    char* func_id_;
    ASTExpressionList* arg_list_;

   public:
    ASTFuncCall(char* func_id, ASTExpressionList* arg_list);
    virtual void Print(GraphGenerator*);
};

class ASTIDExpr : public ASTExpr {
   private:
    char* id;

   public:
    ASTIDExpr(char* id);
    virtual void Print(GraphGenerator*);
};

#endif  // OPC_AST_AST_EXPR_H