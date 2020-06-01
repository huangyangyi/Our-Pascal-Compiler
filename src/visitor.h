#ifndef OPC_VISITOR_H
#define OPC_VISITOR_H

#include <memory>
#include <ast/ast_expr.h>
#include "ast/ast.h"
using namespace std;

class VisitorResult {

};

class Visitor {

public:
    virtual ~Visitor() = default;

    virtual shared_ptr<VisitorResult> VisitASTNode(ASTNode *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTNameList(ASTNameList *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTExpressionList(ASTExpressionList *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTBinaryExpr(ASTBinaryExpr *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTUnaryExpr(ASTUnaryExpr *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTPropExpr(ASTPropExpr *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTConstValueExpr(ASTConstValueExpr *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTFuncCall(ASTFuncCall *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTIDExpr(ASTIDExpr *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTArrayExpr(ASTArrayExpr *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTProgramHead(ASTProgramHead *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTRoutineHead(ASTRoutineHead *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTRoutineBody(ASTRoutineBody *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTRoutine(ASTRoutine *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTProgram(ASTProgram *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTRoutinePart(ASTRoutinePart *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTFuncProcBase(ASTFuncProcBase *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTFunctionHead(ASTFunctionHead *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTProcedureHead(ASTProcedureHead *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTParaDeclList(ASTParaDeclList *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTParaTypeList(ASTParaTypeList *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTVarParaList(ASTVarParaList *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTValParaList(ASTValParaList *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTNonLabelStmt(ASTNonLabelStmt *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTStmt(ASTStmt *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTStmtList(ASTStmtList *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTAssignStmt(ASTAssignStmt *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTProcStmt(ASTProcStmt *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTIfStmt(ASTIfStmt *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTElseClause(ASTElseClause *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTRepeatStmt(ASTRepeatStmt *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTWhileStmt(ASTWhileStmt *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTForStmt(ASTForStmt *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTCaseStmt(ASTCaseStmt *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTCaseExprList(ASTCaseExprList *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTCaseExpr(ASTCaseExpr *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTGotoStmt(ASTGotoStmt *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTType(ASTType *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTSimpleTypeDecl(ASTSimpleTypeDecl *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTArrayTypeDecl(ASTArrayTypeDecl *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTFieldDecl(ASTFieldDecl *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTFieldDeclList(ASTFieldDeclList *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTRecordTypeDecl(ASTRecordTypeDecl *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTTypeDefinition(ASTTypeDefinition *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTTypeDeclList(ASTTypeDeclList *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTTypePart(ASTTypePart *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTConstValue(ASTConstValue *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTConstExprList(ASTConstExprList *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTConstExpr(ASTConstExpr *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTConstPart(ASTConstPart *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTVarPart(ASTVarPart *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTVarDeclList(ASTVarDeclList *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTVarDecl(ASTVarDecl *node) = 0;

    virtual shared_ptr<VisitorResult> VisitASTExitStmt(ASTExitStmt *node) = 0;
};

#endif  // OPC_VISITOR_H
