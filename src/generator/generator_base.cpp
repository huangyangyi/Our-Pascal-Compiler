#include "generator.h"
#include "generator_result.hpp"


std::shared_ptr<VisitorResult> VisitASTNode(ASTNode *node) {
    return std::make_shared<VisitorResult>();
}

std::shared_ptr<VisitorResult> VisitASTNameList(ASTNameList *node) {
    return std::make_shared<NameList>(node->get_identifier_list());
}