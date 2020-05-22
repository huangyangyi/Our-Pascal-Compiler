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
    ASTNode();
    void set_location(int line, int col);
    int line();
    int col();
    virtual void Print(GraphGenerator *) const = 0;
};

class ASTNameList: public ASTNode{
public:
    void addIDENTIFIER(char *);
private:
    std::vector< char *> identifierList;
};

#endif //OPC_AST_AST_BASE_H