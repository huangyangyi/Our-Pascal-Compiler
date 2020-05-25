#include "generator.h"

shared_ptr<VisitorResult> Generator::VisitASTProgramHead(ASTProgramHead* node){}

shared_ptr<VisitorResult> Generator::VisitASTRoutineHead(ASTRoutineHead* node){}

shared_ptr<VisitorResult> Generator::VisitASTRoutineBody(ASTRoutineBody* node){}

shared_ptr<VisitorResult> Generator::VisitASTRoutine(ASTRoutine* node){}

shared_ptr<VisitorResult> Generator::VisitASTProgram(ASTProgram* node){}

shared_ptr<VisitorResult> Generator::VisitASTRoutinePart(ASTRoutinePart* node){}

shared_ptr<VisitorResult> Generator::VisitASTFuncProcBase(ASTFuncProcBase* node){}

shared_ptr<VisitorResult> Generator::VisitASTFunctionDecl(ASTFunctionDecl* node){}

shared_ptr<VisitorResult> Generator::VisitASTFunctionHead(ASTFunctionHead* node){}

shared_ptr<VisitorResult> Generator::VisitASTProcedureDecl(ASTProcedureDecl* node){}

shared_ptr<VisitorResult> Generator::VisitASTProcedureHead(ASTProcedureHead* node){}

shared_ptr<VisitorResult> Generator::VisitASTParaDeclList(ASTParaDeclList* node){}

shared_ptr<VisitorResult> Generator::VisitASTParaTypeList(ASTParaTypeList* node){}

shared_ptr<VisitorResult> Generator::VisitASTVarParaList(ASTVarParaList* node){
    //just delete it, visit them in 
}

shared_ptr<VisitorResult> Generator::VisitASTValParaList(ASTValParaList* node){}