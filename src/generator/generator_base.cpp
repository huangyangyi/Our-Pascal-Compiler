#include "generator.h"
#include "generator_result.hpp"


std::shared_ptr<VisitorResult> VisitASTNode(ASTNode *node) {
    return nullptr;
}

std::shared_ptr<VisitorResult> VisitASTNameList(ASTNameList *node) {
    return std::make_shared<NameList>(node->GetIdentifierList());
}