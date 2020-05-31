#include "ast_base.h"
#include "../visitor.h"
#include <stdlib.h>

int ASTNode::line() { return this->line_; }

int ASTNode::col() { return this->col_; }

std::string ASTNode::get_location() {
    return "line " + string(to_string(this->line())) +
           " , col " + string(to_string(this->col())) + " : ";
}

std::pair<int, int> ASTNode::get_location_pairs(){
    return std::make_pair(this->line(), this->col());
}

void ASTNode::set_location(int line, int col) {
    this->line_ = line;
    this->col_ = col;
}

std::shared_ptr<VisitorResult> ASTNode::Accept(Visitor *visitor) { return visitor->VisitASTNode(this); }

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

std::shared_ptr<VisitorResult> ASTNameList::Accept(Visitor *visitor) { return visitor->VisitASTNameList(this); }

const std::vector<std::string> &ASTNameList::GetIdentifierList() { return this->identifier_list_; }