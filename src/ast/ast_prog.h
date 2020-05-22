#include "ast_base.h"
#include "ast_expr.h"
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_value.h"

class ASTProgramHead;
class ASTRoutineHead;
class ASTRoutineBody;
class ASTRoutine;
class ASTProgram;

class ASTProgramHead : public ASTNode {
public:
  ASTProgramHead(std::string prog_name);
  virtual void Print(GraphGenerator *);

private:
  std::string id;
}

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
}

class ASTRoutineBody : public ASTNode {
public:
  ASTRoutineBody(CompoundStmt *compound_stmt);
  virtual void Print(GraphGenerator *);

private:
  CompoundStmt *compound_stmt;
}

class ASTRoutine : public ASTNode {
public:
  ASTRoutine(ASTRoutineRead *routine_head, ASTRoutineBody *routine_body);
  virtual void Print(GraphGenerator *);

private:
  ASTRoutineHead *routine_head;
  ASTRoutineBody *routine_body;
}

class ASTProgram : public ASTNode {
public:
  ASTProgram(ASTProgramHead *, ASTRoutine *);
  virtual void Print(GraphGenerator *);

private:
  ASTProgramHead *program_head;
  ASTRoutine *routine;
}

class ASTFunctionDecl : public ASTNode {
public:
  ASTFunctionDecl(ASTFunctionHead *, ASTRoutine *);
  virtual void Print(GraphGenerator *);

private:
  ASTFunctionHead *function_head;
  ASTRoutine *routine;
};

class ASTFunctionHead : public ASTNode {
public:
  ASTFunctionHead(ASTParameters *, ASTSimpleTypeDecl *);
  virtual void Print(GraphGenerator *);

private:
  ASTParameters *parameters;
  ASTSimpleTypeDecl *simple_type_decl;
};

class ASTProcedureDecl : public ASTNode {
public:
  ASTProcedureDecl(ASTProcedureHead *, ASTRoutine *);
  virtual void Print(GraphGenerator *);

private:
  ASTProcedureHead *procedure_head;
  ASTRoutine *routine;
};

class ASTProcedureHead : public ASTNode {
public:
  ASTProcedureHead(ASTParameters *);
  virtual void Print(GraphGenerator *);

private:
  ASTParameters *parameters;
};

class ASTParameters : public ASTNode {
public:
  ASTParameters(ASTParaDecList *);
  virtual void Print(GraphGenerator *);

private:
  ASTParaDecList *para_dec_list;
};

class ASTParaDeclList : public ASTNode {
public:
  ASTParaDeclList(ASTParaDeclList *, ASTParaTypeList *);
  virtual void Print(GraphGenerator *);

private:
  ASTParaDeclList *para_decl_list;
  ASTParaTypeList *para_type_list;
};

class ASTParaTypeList : public ASTNode {
public:
  ASTParaTypeList(ASTVarParaList *, ASTSimpleTypeDecl *);
  virtual void Print(GraphGenerator *);

private:
  ASTVarParaList *var_para_list;
  ASTSimpleTypeDecl *simple_type_decl;
};

class ASTVarParaList : public ASTNode {
public:
  ASTVarParaList(ASTNameList *);
  virtual void Print(GraphGenerator *);

private:
  ASTNameList *name_list;
};

class ASTValParaList : public ASTNode {
public:
  ASTValParaList(ASTNameList *);
  virtual void Print(GraphGenerator *);

private:
  ASTNameList *name_list;
};