#ifndef OPC_AST_GRAPH_GENERATOR_H
#define OPC_AST_GRAPH_GENERATOR_H
#include<string>
#include<stack>
#include "ast_value.h"

class GraphGenerator {
    private:
     int id_cnt_=0;
     std::stack<int> stk_;
     std::vector<std::string> nodes_;
     std::vector<std::string> edges_;

    public:
     GraphGenerator() = default;
     ~GraphGenerator() = default;
     void AddNode(std::string label, int line, int col);
     void AddValue(std::string value_type, std::string content);
     void AddIdentifier(std::string content);
     void Pop();
     void Save(std::string path);
};

#endif