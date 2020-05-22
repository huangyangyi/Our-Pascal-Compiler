#include "ast_prog.h"

ASTProgramHead::ASTProgramHead(char *id) :id(id){}
void ASTProgramHead::Print(GraphGenerator *g){
    g->AddNode("program_head", this->line(), this->col());
    g->AddIdentifier(id);
    g->Pop();
}

ASTRoutineHead::ASTRoutineHead(ASTConstPart* const_part, ASTTypePart* type_part, ASTVarPart* var_part, ASTRoutinePart* routine_part)
    :const_part(const_part), type_part(type_part), var_part(var_part), routine_part(routine_part){}
void ASTRoutineHead::Print(GraphGenerator *g){
    g->AddNode("routine_head", this->line(), this->col());
    if (const_part != nullptr)
        const_part->Print(g);
    if (type_part != nullptr)
        type_part->Print(g);
    if (var_part != nullptr)
        var_part->Print(g);
    if (routine_part != nullptr)
        routine_part->Print(g);
    g->Pop();
}

ASTRoutineBody::ASTRoutineBody(CompoundStmt* compound_stmt): compound_stmt(compound_stmt){}
void ASTRoutineBody:: Print(GraphGenerator *g){
    g->AddNode("routine_body", this->line(), this->col());
    routine_body->Print(g);
    g->Pop();
}


ASTRoutine::ASTRoutine(ASTRoutineRead* routine_head, ASTRoutineBody* routine_body)
    :routine_head(routine_head), routine_body(routine_body){}
void ASTRoutine::Print(GraphGenerator *g){
    g->AddNode("routine", this->line(), this->col());
    routine_head->Print(g);
    routine_body->Print(g);
    g->Pop();
}


ASTProgram::ASTProgram(ASTProgramHead* program_head, ASTRoutine* routine): program_head(program_head), routine(routine){}
void ASTProgram::Print(GraphGenerator *g){
        g->AddNode("program", this->line(), this->col());
        program_head->Print(g);
        routine->Print(g);
        g->Pop();
    }
}