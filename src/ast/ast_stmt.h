#include "ast_base.h"

class ASTNonLabelStmt;
class ASTStmt;
class ASTStmtList;
class ASTAssignStmt;
class ASTProcStmt;
class ASTCompoundStmt;
class ASTIfStmt;
class ASTElseClause;
class ASTRepeatStmt;
class ASTWhileStmt;
class ASTForStmt;
class ASTCaseStmt;
class ASTCaseExprList;
class ASTCaseExpr;
class ASTGotoStmt;

class ASTNonLabelStmt : public ASTNode {
   public:
    virtual void Print(GraphGenerator *graph);
};

class ASTStmt : public ASTNode {
   private:
    int label_;
    ASTNonLabelStmt non_label_stmt_;
   public:

    ASTStmt(ASTNonLabelStmt *, char *);
    ASTStmt(ASTNonLabelStmt *);
    virtual void Print(GraphGenerator *graph);
};

class ASTStmtList : public ASTNode {
   public:
};

class ASTAssignStmt : public ASTNonLabelStmt {};

class ASTProcStmt : public ASTNonLabelStmt {};

class ASTCompoundStmt : public ASTNonLabelStmt {};

class ASTIfStmt : public ASTNonLabelStmt {};

class ASTElseClause : public ASTNode {};

class ASTRepeatStmt : public ASTNonLabelStmt {};

class ASTWhileStmt : public ASTNonLabelStmt {};

class ASTForStmt : public ASTNonLabelStmt {
    enum class ForDir { TO, DOWNTO };
};

class ASTCaseStmt : public ASTNonLabelStmt {};

class ASTCaseExprList : public ASTNode {};

class ASTCaseExpr : public ASTNode {};

class ASTGotoStmt : public ASTNonLabelStmt {};