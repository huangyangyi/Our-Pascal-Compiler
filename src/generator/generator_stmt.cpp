#include "generator.h"

std::shared_ptr<VisitorResult> Generator::VisitASTNonLabelStmt(ASTNonLabelStmt* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTStmt(ASTStmt* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTStmtList(ASTStmtList* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTAssignStmt(ASTAssignStmt* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTProcStmt(ASTProcStmt* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTIfStmt(ASTIfStmt* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTElseClause(ASTElseClause* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTRepeatStmt(ASTRepeatStmt* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTWhileStmt(ASTWhileStmt* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTForStmt(ASTForStmt* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTCaseStmt(ASTCaseStmt* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTCaseExprList(ASTCaseExprList* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTCaseExpr(ASTCaseExpr* node){}

std::shared_ptr<VisitorResult> Generator::VisitASTGotoStmt(ASTGotoStmt* node){}