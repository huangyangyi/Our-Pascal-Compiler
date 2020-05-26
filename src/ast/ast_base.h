#ifndef OPC_AST_AST_BASE_H
#define OPC_AST_AST_BASE_H

#include <vector>
#include <string>
#include <assert.h>
#include "graph_generator.h"
#include "../visitor.h"

class Visitor;

class ASTNode;

class ASTNode;

class ASTNameList;

class ASTNode {
private:
    int line_, col_;

public:
    ASTNode() = default;

    void set_location(int line, int col);

    int line();

    int col();

    virtual void Print(GraphGenerator *) = 0;

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *) = 0;
};

class ASTNameList : public ASTNode {
public:
    ASTNameList() = default;

    void AddIdentifier(std::string);

    virtual void Print(GraphGenerator *);

    virtual std::shared_ptr<VisitorResult> Accept(Visitor *visitor);

    const std::vector<std::string> &GetIdentifierList();

private:
    std::vector<std::string> identifier_list_;
};

#endif //OPC_AST_AST_BASE_H