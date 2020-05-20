#ifndef OPC_AST_AST_EXPR_H
#define OPC_AST_AST_EXPR_H
class ASTExpr;
class ASTExpressionList;
class ASTBinaryExpr;
class ASTConstExpr;
class ASTIDExpr;
class ASTExpr : public ASTNode {};

class ASTExpressionList : public ASTNode {
public:
    ASTExpressionList(ASTExpr* expr);
    AddExpr(ASTExpr* expr);

   private:
    std::vector<ASTExpr*> expr_list;
    
};

class ASTBinaryExpr: public ASTExpr {
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
    ASTBinaryExpr(Oper, ASTExpr*, ASTExpr*);
};

class ASTUnaryExpr: public ASTExpr {
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
    ASTUnaryExpr(Oper, ASTExpr*);
};
#endif //OPC_AST_AST_EXPR_H