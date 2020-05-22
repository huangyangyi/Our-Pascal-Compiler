ASTFunctionDecl::ASTFunctionDecl(ASTFunctionHead* function_head, ASTRoutine* routine): function_head(function_head), routine(routine) {}
void ASTFunctionDecl::Print(GraphGenerator* g){
	g->AddNode("function_decl", this->line(), this->col());
	
	g->Pop();
}

ASTFunctionHead::ASTFunctionHead(ASTParameters* parameters, ASTSimpleTypeDecl* simple_type_decl): parameters(parameters), simple_type_decl(simple_type_decl) {}
void ASTFunctionHead::Print(GraphGenerator* g){
	g->AddNode("function_head", this->line(), this->col());
	
	g->Pop();
}

ASTProcedureDecl::ASTProcedureDecl(ASTProcedureHead* procedure_head, ASTRoutine* routine): procedure_head(procedure_head), routine(routine) {}
void ASTProcedureDecl::Print(GraphGenerator* g){
	g->AddNode("procedure_decl", this->line(), this->col());
	
	g->Pop();
}

ASTProcedureHead::ASTProcedureHead(ASTParameters* parameters): parameters(parameters) {}
void ASTProcedureHead::Print(GraphGenerator* g){
	g->AddNode("procedure_head", this->line(), this->col());
	
	g->Pop();
}

ASTParameters::ASTParameters(ASTParaDecList* para_dec_list): para_dec_list(para_dec_list) {}
void ASTParameters::Print(GraphGenerator* g){
	g->AddNode("parameters", this->line(), this->col());
	
	g->Pop();
}

ASTParaDeclList::ASTParaDeclList(ASTParaDeclList* para_decl_list, ASTParaTypeList* para_type_list): para_decl_list(para_decl_list), para_type_list(para_type_list) {}
void ASTParaDeclList::Print(GraphGenerator* g){
	g->AddNode("para_decl_list", this->line(), this->col());
	
	g->Pop();
}

ASTParaTypeList::ASTParaTypeList(ASTVarParaList* var_para_list, ASTSimpleTypeDecl* simple_type_decl): var_para_list(var_para_list), simple_type_decl(simple_type_decl) {}
void ASTParaTypeList::Print(GraphGenerator* g){
	g->AddNode("para_type_list", this->line(), this->col());
	
	g->Pop();
}

ASTVarParaList::ASTVarParaList(ASTNameList* name_list): name_list(name_list) {}
void ASTVarParaList::Print(GraphGenerator* g){
	g->AddNode("var_para_list", this->line(), this->col());
	
	g->Pop();
}

ASTValParaList::ASTValParaList(ASTNameList* name_list): name_list(name_list) {}
void ASTValParaList::Print(GraphGenerator* g){
	g->AddNode("val_para_list", this->line(), this->col());
	
	g->Pop();
}

ASTCompoundStmt::ASTCompoundStmt(ASTStmtList* stmt_list): stmt_list(stmt_list) {}
void ASTCompoundStmt::Print(GraphGenerator* g){
	g->AddNode("compound_stmt", this->line(), this->col());
	
	g->Pop();
}

ASTStmtList::ASTStmtList(ASTStmtList* stmt_list, ASTStmt* stmt): stmt_list(stmt_list), stmt(stmt) {}
void ASTStmtList::Print(GraphGenerator* g){
	g->AddNode("stmt_list", this->line(), this->col());
	
	g->Pop();
}

ASTStmt::ASTStmt(ASTNonLabelStmt{* non_label_stmt{): non_label_stmt{(non_label_stmt{) {}
void ASTStmt::Print(GraphGenerator* g){
	g->AddNode("stmt", this->line(), this->col());
	
	g->Pop();
}

ASTNonLabelStmt::ASTNonLabelStmt(ASTAssignStmt{* assign_stmt{): assign_stmt{(assign_stmt{) {}
void ASTNonLabelStmt::Print(GraphGenerator* g){
	g->AddNode("non_label_stmt", this->line(), this->col());
	
	g->Pop();
}

ASTAssignStmt::ASTAssignStmt(ASTExpression{* expression{): expression{(expression{) {}
void ASTAssignStmt::Print(GraphGenerator* g){
	g->AddNode("assign_stmt", this->line(), this->col());
	
	g->Pop();
}

ASTProcStmt::ASTProcStmt(ASTExpressionList* expression_list, ASTFactor* factor): expression_list(expression_list), factor(factor) {}
void ASTProcStmt::Print(GraphGenerator* g){
	g->AddNode("proc_stmt", this->line(), this->col());
	
	g->Pop();
}

ASTIfStmt::ASTIfStmt(ASTExpression* expression, ASTStmt* stmt, ASTElseClause* else_clause): expression(expression), stmt(stmt), else_clause(else_clause) {}
void ASTIfStmt::Print(GraphGenerator* g){
	g->AddNode("if_stmt", this->line(), this->col());
	
	g->Pop();
}

ASTElseClause::ASTElseClause(ASTStmt* stmt): stmt(stmt) {}
void ASTElseClause::Print(GraphGenerator* g){
	g->AddNode("else_clause", this->line(), this->col());
	
	g->Pop();
}

ASTRepeatStmt::ASTRepeatStmt(ASTStmtList* stmt_list, ASTExpression* expression): stmt_list(stmt_list), expression(expression) {}
void ASTRepeatStmt::Print(GraphGenerator* g){
	g->AddNode("repeat_stmt", this->line(), this->col());
	
	g->Pop();
}

ASTWhileStmt::ASTWhileStmt(ASTExpression* expression, ASTStmt* stmt): expression(expression), stmt(stmt) {}
void ASTWhileStmt::Print(GraphGenerator* g){
	g->AddNode("while_stmt", this->line(), this->col());
	
	g->Pop();
}

ASTForStmt::ASTForStmt(ASTExpression* expression, ASTDirection* direction, ASTExpression* expression, ASTStmt* stmt): expression(expression), direction(direction), expression(expression), stmt(stmt) {}
void ASTForStmt::Print(GraphGenerator* g){
	g->AddNode("for_stmt", this->line(), this->col());
	
	g->Pop();
}

ASTDirection::ASTDirection():  {}
void ASTDirection::Print(GraphGenerator* g){
	g->AddNode("direction", this->line(), this->col());
	
	g->Pop();
}

ASTCaseStmt::ASTCaseStmt(ASTExpression* expression, ASTCaseExprList* case_expr_list): expression(expression), case_expr_list(case_expr_list) {}
void ASTCaseStmt::Print(GraphGenerator* g){
	g->AddNode("case_stmt", this->line(), this->col());
	
	g->Pop();
}

ASTCaseExprList::ASTCaseExprList(ASTCaseExprList* case_expr_list, ASTCaseExpr* case_expr): case_expr_list(case_expr_list), case_expr(case_expr) {}
void ASTCaseExprList::Print(GraphGenerator* g){
	g->AddNode("case_expr_list", this->line(), this->col());
	
	g->Pop();
}

ASTCaseExpr::ASTCaseExpr(ASTConstValue* const_value, ASTStmt* stmt): const_value(const_value), stmt(stmt) {}
void ASTCaseExpr::Print(GraphGenerator* g){
	g->AddNode("case_expr", this->line(), this->col());
	
	g->Pop();
}

ASTGotoStmt::ASTGotoStmt():  {}
void ASTGotoStmt::Print(GraphGenerator* g){
	g->AddNode("goto_stmt", this->line(), this->col());
	
	g->Pop();
}

