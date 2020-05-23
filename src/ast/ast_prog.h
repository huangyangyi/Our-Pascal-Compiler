#ifndef OPC_AST_PROG_H
#define OPC_AST_PROG_H

#include "ast_base.h"
#include "ast_expr.h"
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_value.h"

class ASTProgramHead;
class ASTRoutineHead;
class ASTRoutineBody;
class ASTRoutinePart;
class ASTRoutine;
class ASTFuncProcBase;
class ASTProgram;
class ASTFunctionDecl;
class ASTFunctionHead;
class ASTProcedureDecl;
class ASTProcedureHead;
class ASTParaTypeList;
class ASTParaList;
class ASTParaDeclList;

class ASTProgramHead : public ASTNode {
   public:
    ASTProgramHead(std::string id);
    virtual void Print(GraphGenerator *);

   private:
    std::string id;
};

class ASTRoutineHead : public ASTNode {
   public:
    ASTRoutineHead(ASTConstPart *const_part, ASTTypePart *type_part,
                   ASTVarPart *var_part, ASTRoutinePart *routine_part);
    virtual void Print(GraphGenerator *);

   private:
    ASTConstPart *const_part;
    ASTTypePart *type_part;
    ASTVarPart *var_part;
    ASTRoutinePart *routine_part;
};

class ASTRoutineBody : public ASTNode {
   public:
    ASTRoutineBody(ASTStmtList *compound_stmt);
    virtual void Print(GraphGenerator *);

   private:
    ASTStmtList *compound_stmt;
};

class ASTRoutine : public ASTNode {
   public:
    ASTRoutine(ASTRoutineHead *routine_head, ASTRoutineBody *routine_body);
    virtual void Print(GraphGenerator *);

   private:
    ASTRoutineHead *routine_head;
    ASTRoutineBody *routine_body;
};

class ASTProgram : public ASTNode {
   public:
    ASTProgram(ASTProgramHead *, ASTRoutine *);
    virtual void Print(GraphGenerator *);

   private:
    ASTProgramHead *program_head;
    ASTRoutine *routine;
};

class ASTRoutinePart : public ASTNode {
   public:
    ASTRoutinePart(ASTFuncProcBase *);
    virtual void Print(GraphGenerator *);
    void addFuncProcDecl(ASTFuncProcBase *);

   private:
    std::vector<ASTFuncProcBase *> routine_list;
};

class ASTFuncProcBase : public ASTNode {
   public:
    enum class FuncType { FUNCTION, PROCEDURE };
    FuncType iam;
    ASTFuncProcBase(FuncType whoami) : iam(whoami) {}
    virtual void Print(GraphGenerator *) {}
};

class ASTFunctionDecl : public ASTFuncProcBase {
   public:
    ASTFunctionDecl(ASTFunctionHead *, ASTRoutine *);
    virtual void Print(GraphGenerator *);

   private:
    ASTFunctionHead *function_head;
    ASTRoutine *routine;
};

class ASTFunctionHead : public ASTNode {
   public:
    ASTFunctionHead(std::string, ASTParaDeclList *, ASTSimpleTypeDecl *);
    virtual void Print(GraphGenerator *);

   private:
    std::string func_name;
    ASTParaDeclList *parameters;
    ASTSimpleTypeDecl *simple_type_decl;
};

class ASTProcedureDecl : public ASTFuncProcBase {
   public:
    ASTProcedureDecl(ASTProcedureHead *, ASTRoutine *);
    virtual void Print(GraphGenerator *);

   private:
    ASTProcedureHead *procedure_head;
    ASTRoutine *routine;
};

class ASTProcedureHead : public ASTNode {
   public:
    ASTProcedureHead(std::string proc_name, ASTParaDeclList *);
    virtual void Print(GraphGenerator *);

   private:
    std::string proc_name;
    ASTParaDeclList *parameters;
};

/*
 * not required in yacc
 *
class ASTParameters : public ASTNode {
   public:
    ASTParameters(ASTParaDeclList *);
    virtual void Print(GraphGenerator *);

   private:
    ASTParaDeclList *para_dec_list;
};
*/

class ASTParaDeclList : public ASTNode {
   public:
    ASTParaDeclList(ASTParaTypeList *);
    void addParaTypeList(ASTParaTypeList *);
    virtual void Print(GraphGenerator *);

   private:
    std::vector<ASTParaTypeList *> para_decl_list;
};

class ASTParaTypeList : public ASTNode {
   public:
    ASTParaTypeList(ASTParaList *, ASTSimpleTypeDecl *);
    virtual void Print(GraphGenerator *);

   private:
    ASTParaList *para_list;
    ASTSimpleTypeDecl *simple_type_decl;
};

class ASTParaList : public ASTNode {
   public:
    bool isVar;
    ASTParaList(bool isVar) : isVar(isVar) {}
};

class ASTVarParaList : public ASTParaList {
   public:
    ASTVarParaList(ASTNameList *);
    virtual void Print(GraphGenerator *);

   private:
    ASTNameList *name_list;
};

class ASTValParaList : public ASTParaList {
   public:
    ASTValParaList(ASTNameList *);
    virtual void Print(GraphGenerator *);

   private:
    ASTNameList *name_list;
};

#endif