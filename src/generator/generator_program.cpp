#include "generator.h"

std::shared_ptr<VisitorResult> Generator::VisitASTProgramHead(ASTProgramHead *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTRoutineHead(ASTRoutineHead *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTRoutineBody(ASTRoutineBody *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTRoutine(ASTRoutine *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTProgram(ASTProgram *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTRoutinePart(ASTRoutinePart *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTFuncProcBase(ASTFuncProcBase *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTFunctionDecl(ASTFunctionDecl *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTFunctionHead(ASTFunctionHead *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTProcedureDecl(ASTProcedureDecl *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTProcedureHead(ASTProcedureHead *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTParaDeclList(ASTParaDeclList *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTParaTypeList(ASTParaTypeList *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTVarParaList(ASTVarParaList *node) {
    //just delete it, visit them in 
}

std::shared_ptr<VisitorResult> Generator::VisitASTValParaList(ASTValParaList *node) {}