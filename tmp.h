class ASTFunctionDecl: public ASTNode{
public:	
	ASTFunctionDecl(ASTFunctionHead*, ASTRoutine*);
	virtual void Print(GraphGenerator*);
private:
	ASTFunctionHead* function_head;
	ASTRoutine* routine;
};

class ASTFunctionHead: public ASTNode{
public:	
	ASTFunctionHead(ASTParameters*, ASTSimpleTypeDecl*);
	virtual void Print(GraphGenerator*);
private:
	ASTParameters* parameters;
	ASTSimpleTypeDecl* simple_type_decl;
};

class ASTProcedureDecl: public ASTNode{
public:	
	ASTProcedureDecl(ASTProcedureHead*, ASTRoutine*);
	virtual void Print(GraphGenerator*);
private:
	ASTProcedureHead* procedure_head;
	ASTRoutine* routine;
};

class ASTProcedureHead: public ASTNode{
public:	
	ASTProcedureHead(ASTParameters*);
	virtual void Print(GraphGenerator*);
private:
	ASTParameters* parameters;
};

class ASTParameters: public ASTNode{
public:	
	ASTParameters(ASTParaDecList*);
	virtual void Print(GraphGenerator*);
private:
	ASTParaDecList* para_dec_list;
};

class ASTParaDeclList: public ASTNode{
public:	
	ASTParaDeclList(ASTParaDeclList*, ASTParaTypeList*);
	virtual void Print(GraphGenerator*);
private:
	ASTParaDeclList* para_decl_list;
	ASTParaTypeList* para_type_list;
};

class ASTParaTypeList: public ASTNode{
public:	
	ASTParaTypeList(ASTVarParaList*, ASTSimpleTypeDecl*);
	virtual void Print(GraphGenerator*);
private:
	ASTVarParaList* var_para_list;
	ASTSimpleTypeDecl* simple_type_decl;
};

class ASTVarParaList: public ASTNode{
public:	
	ASTVarParaList(ASTNameList*);
	virtual void Print(GraphGenerator*);
private:
	ASTNameList* name_list;
};

class ASTValParaList: public ASTNode{
public:	
	ASTValParaList(ASTNameList*);
	virtual void Print(GraphGenerator*);
private:
	ASTNameList* name_list;
};

class ASTCompoundStmt: public ASTNode{
public:	
	ASTCompoundStmt(ASTStmtList*);
	virtual void Print(GraphGenerator*);
private:
	ASTStmtList* stmt_list;
};

class ASTStmtList: public ASTNode{
public:	
	ASTStmtList(ASTStmtList*, ASTStmt*);
	virtual void Print(GraphGenerator*);
private:
	ASTStmtList* stmt_list;
	ASTStmt* stmt;
};

class ASTStmt: public ASTNode{
public:	
	ASTStmt(ASTNonLabelStmt{*);
	virtual void Print(GraphGenerator*);
private:
	ASTNonLabelStmt{* non_label_stmt{;
};

class ASTNonLabelStmt: public ASTNode{
public:	
	ASTNonLabelStmt(ASTAssignStmt{*);
	virtual void Print(GraphGenerator*);
private:
	ASTAssignStmt{* assign_stmt{;
};

class ASTAssignStmt: public ASTNode{
public:	
	ASTAssignStmt(ASTExpression{*);
	virtual void Print(GraphGenerator*);
private:
	ASTExpression{* expression{;
};

class ASTProcStmt: public ASTNode{
public:	
	ASTProcStmt(ASTExpressionList*, ASTFactor*);
	virtual void Print(GraphGenerator*);
private:
	ASTExpressionList* expression_list;
	ASTFactor* factor;
};

class ASTIfStmt: public ASTNode{
public:	
	ASTIfStmt(ASTExpression*, ASTStmt*, ASTElseClause*);
	virtual void Print(GraphGenerator*);
private:
	ASTExpression* expression;
	ASTStmt* stmt;
	ASTElseClause* else_clause;
};

class ASTElseClause: public ASTNode{
public:	
	ASTElseClause(ASTStmt*);
	virtual void Print(GraphGenerator*);
private:
	ASTStmt* stmt;
};

class ASTRepeatStmt: public ASTNode{
public:	
	ASTRepeatStmt(ASTStmtList*, ASTExpression*);
	virtual void Print(GraphGenerator*);
private:
	ASTStmtList* stmt_list;
	ASTExpression* expression;
};

class ASTWhileStmt: public ASTNode{
public:	
	ASTWhileStmt(ASTExpression*, ASTStmt*);
	virtual void Print(GraphGenerator*);
private:
	ASTExpression* expression;
	ASTStmt* stmt;
};

class ASTForStmt: public ASTNode{
public:	
	ASTForStmt(ASTExpression*, ASTDirection*, ASTExpression*, ASTStmt*);
	virtual void Print(GraphGenerator*);
private:
	ASTExpression* expression;
	ASTDirection* direction;
	ASTExpression* expression;
	ASTStmt* stmt;
};

class ASTDirection: public ASTNode{
public:	
	ASTDirection();
	virtual void Print(GraphGenerator*);
private:
};

class ASTCaseStmt: public ASTNode{
public:	
	ASTCaseStmt(ASTExpression*, ASTCaseExprList*);
	virtual void Print(GraphGenerator*);
private:
	ASTExpression* expression;
	ASTCaseExprList* case_expr_list;
};

class ASTCaseExprList: public ASTNode{
public:	
	ASTCaseExprList(ASTCaseExprList*, ASTCaseExpr*);
	virtual void Print(GraphGenerator*);
private:
	ASTCaseExprList* case_expr_list;
	ASTCaseExpr* case_expr;
};

class ASTCaseExpr: public ASTNode{
public:	
	ASTCaseExpr(ASTConstValue*, ASTStmt*);
	virtual void Print(GraphGenerator*);
private:
	ASTConstValue* const_value;
	ASTStmt* stmt;
};

class ASTGotoStmt: public ASTNode{
public:	
	ASTGotoStmt();
	virtual void Print(GraphGenerator*);
private:
};

