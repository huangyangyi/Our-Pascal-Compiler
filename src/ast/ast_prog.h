#ifndef OPC_AST_PROG_H
#define OPC_AST_PROG_H

#include "ast_base.h"
#include "ast_expr.h"
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_value.h"

class Visitor;

class ASTNode;

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

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

private:
public:
    const string &getId() const;

private:
    std::string id;
};

class ASTRoutineHead : public ASTNode {
public:
    ASTRoutineHead(ASTConstPart *const_part, ASTTypePart *type_part,
                   ASTVarPart *var_part, ASTRoutinePart *routine_part);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

private:
    ASTConstPart *const_part;
    ASTTypePart *type_part;
public:
    ASTConstPart *getConstPart() const;

    ASTTypePart *getTypePart() const;

    ASTVarPart *getVarPart() const;

    ASTRoutinePart *getRoutinePart() const;

private:
    ASTVarPart *var_part;
    ASTRoutinePart *routine_part;
};

class ASTRoutineBody : public ASTNode {
public:
    ASTRoutineBody(ASTStmtList *compound_stmt);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTStmtList *getCompoundStmt();

private:
    ASTStmtList *compound_stmt;
};

class ASTRoutine : public ASTNode {
public:
    ASTRoutine(ASTRoutineHead *routine_head, ASTRoutineBody *routine_body);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTRoutineHead *getRoutineHead() const;

    ASTRoutineBody *getRoutineBody() const;

private:
    ASTRoutineHead *routine_head;
    ASTRoutineBody *routine_body;
};

class ASTProgram : public ASTNode {
public:
    ASTProgram(ASTProgramHead *, ASTRoutine *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTProgramHead *getProgramHead() const;

    ASTRoutine *getRoutine() const;

private:
    ASTProgramHead *program_head;
    ASTRoutine *routine;
};

class ASTRoutinePart : public ASTNode {
public:
    ASTRoutinePart(ASTFuncProcBase *);

    virtual void Print(GraphGenerator *);

    void addFuncProcDecl(ASTFuncProcBase *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

private:
    std::vector<ASTFuncProcBase *> routine_list;
public:
    const vector<ASTFuncProcBase *> &getRoutineList() const;
};

class ASTFuncProcBase : public ASTNode {
public:
    enum class FuncType {
        FUNCTION, PROCEDURE
    };
    FuncType iam;

    FuncType getIam() const;

    ASTFuncProcBase(FuncType whoami) : iam(whoami) {}

    virtual void Print(GraphGenerator *) {}

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);
};

class ASTFunctionDecl : public ASTFuncProcBase {
public:
    ASTFunctionDecl(ASTFunctionHead *, ASTRoutine *);

    virtual void Print(GraphGenerator *);

    ASTFunctionHead *getFunctionHead() const;

    ASTRoutine *getRoutine() const;

private:
    ASTFunctionHead *function_head;
    ASTRoutine *routine;
};

class ASTFunctionHead : public ASTNode {
public:
    ASTFunctionHead(std::string, ASTParaDeclList *, ASTSimpleTypeDecl *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const string &getFuncName() const;

    ASTParaDeclList *getParameters() const;

    ASTSimpleTypeDecl *getSimpleTypeDecl() const;

private:
    std::string func_name;
    ASTParaDeclList *parameters;
    ASTSimpleTypeDecl *simple_type_decl;
};

class ASTProcedureDecl : public ASTFuncProcBase {
public:
    ASTProcedureDecl(ASTProcedureHead *, ASTRoutine *);

    virtual void Print(GraphGenerator *);

    ASTProcedureHead *getProcedureHead() const;

    ASTRoutine *getRoutine() const;

private:
    ASTProcedureHead *procedure_head;
    ASTRoutine *routine;
};

class ASTProcedureHead : public ASTNode {
public:
    ASTProcedureHead(std::string proc_name, ASTParaDeclList *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const string &getProcName() const;

    ASTParaDeclList *getParameters() const;

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
    ASTParaDeclList();

    void addParaTypeList(ASTParaTypeList *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const vector<ASTParaTypeList *> &getParaDeclList() const;

private:
    std::vector<ASTParaTypeList *> para_decl_list;
};

class ASTParaTypeList : public ASTNode {
public:
    ASTParaTypeList(ASTParaList *, ASTSimpleTypeDecl *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTParaList *getParaList() const;

    ASTSimpleTypeDecl *getSimpleTypeDecl() const;

private:
    ASTParaList *para_list;
    ASTSimpleTypeDecl *simple_type_decl;
};

class ASTParaList : public ASTNode {
public:
    bool is_var;

    bool isVar() const {
        return is_var;
    }

    ASTParaList(bool isVar) : is_var(isVar) {}
};


class ASTVarParaList : public ASTParaList {
public:
    ASTVarParaList(ASTNameList *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTNameList *getNameList() const;

private:
    ASTNameList *name_list;
};

class ASTValParaList : public ASTParaList {
public:
    ASTValParaList(ASTNameList *);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    ASTNameList *getNameList() const;

private:
    ASTNameList *name_list;
};

#endif