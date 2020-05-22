#include "ast_base.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "ast_expr.h"
#include "ast_value.h"

class ASTProgramHead;
class ASTRoutineHead;
class ASTRoutineBody;
class ASTRoutine;
class ASTProgram;

class ASTProgramHead : public ASTNode {
   public:
    ASTProgramHead(char* id);
    virtual void Print(GraphGenerator*);

   private:
    std::string id;
}

class ASTRoutineHead : public ASTNode {
   public:
    ASTRoutineHead(ASTConstPart* const_part, ASTTypePart* type_part,
                   ASTVarPart* var_part, ASTRoutinePart* routine_part);
    virtual void Print(GraphGenerator*);

   private:
    ASTConstPart* const_part;
    ASTTypePart* type_part;
    ASTVarPart* var_part;
    ASTRoutinePart* routine_part;
}

class ASTRoutineBody : public ASTNode {
   public:
    ASTRoutineBody(CompoundStmt* compound_stmt);
    virtual void Print(GraphGenerator*);

   private:
    CompoundStmt* compound_stmt;
}

class ASTRoutine : public ASTNode {
   public:
    ASTRoutine(ASTRoutineRead* routine_head, ASTRoutineBody* routine_body);
    virtual void Print(GraphGenerator*);

   private:
    ASTRoutineHead* routine_head;
    ASTRoutineBody* routine_body;
}

class ASTProgram : public ASTNode {
   public:
    ASTProgram(ASTProgramHead*, ASTRoutine*);
    virtual void Print(GraphGenerator*);

   private:
    ASTProgramHead* program_head;
    ASTRoutine* routine;
}