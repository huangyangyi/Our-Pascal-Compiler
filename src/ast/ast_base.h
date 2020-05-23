#ifndef OPC_AST_AST_BASE_H
#define OPC_AST_AST_BASE_H

#include <vector>
#include <string>
#include <assert.h>
#include "graph_generator.h"

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
};

class ASTNameList: public ASTNode{
public:
    ASTNameList() = default;
    void AddIdentifier(std::string);
    virtual void Print(GraphGenerator *);
private:
    std::vector<std::string> identifier_list_;
};

#endif //OPC_AST_AST_BASE_H