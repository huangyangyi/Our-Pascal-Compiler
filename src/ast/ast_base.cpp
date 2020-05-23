#include "ast_base.h"

int ASTNode::line(){return this->line_;}

int ASTNode::col(){return this->col_;}

void ASTNode::set_location(int line,int col) {
    this->line_ = line;
    this->col_ = col;
}

void ASTNameList::AddIdentifier(std::string id) {
    this->identifier_list_.push_back(id);
}

void ASTNameList::Print(GraphGenerator *g) {
    g->AddNode("name_list", line(), col());
    for (auto id : identifier_list_) {
        g->AddIdentifier(id);
    }
    g->Pop();
}