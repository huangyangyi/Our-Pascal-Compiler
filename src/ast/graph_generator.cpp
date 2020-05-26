#include "graph_generator.h"

#include <fstream>
#include <sstream>

void GraphGenerator::AddNode(std::string label, int line, int col) {
    int id = id_cnt_++;
    std::stringstream ostr("");
    ostr << "node_" << id << "[";
    ostr << "label=\"" << label << "\\n";
    ostr << "[" << line << ", " << col << "]";
    ostr << "\"];";
    std::string node_str = ostr.str();
    nodes_.push_back(node_str);
    std::stringstream ostr1("");
    ostr1.clear();
    if (id != 0) {
        ostr1 << "node_" << stk_.top() << "->"
              << "node_" << id << ";";
        std::string edge_str = ostr1.str();
        edges_.push_back(edge_str);
    }
    stk_.push(id);
}

void GraphGenerator::AddIdentifier(std::string content) {
    int id = id_cnt_++;
    std::stringstream ostr("");
    ostr << "node_" << id << "[";
    ostr << "label=\"<ID>" << content << "\"";
    ostr << "];";
    std::string node_str = ostr.str();
    nodes_.push_back(node_str);
    std::stringstream ostr1("");
    ostr1.clear();
    if (id != 0) {
        ostr1 << "node_" << stk_.top() << "->"
              << "node_" << id << ";";
        std::string edge_str = ostr1.str();
        edges_.push_back(edge_str);
    }
}

void GraphGenerator::AddValue(std::string t, std::string content) {
    int id = id_cnt_++;
    std::stringstream ostr("");
    ostr << "node_" << id << "[";
    ostr << "label=\"<" << t << ">" << content << "\"";
    ostr << "];";
    std::string node_str = ostr.str();
    nodes_.push_back(node_str);
    std::stringstream ostr1("");
    if (id != 0) {
        ostr1 << "node_" << stk_.top() << "->"
              << "node_" << id << ";";
        std::string edge_str = ostr1.str();
        edges_.push_back(edge_str);
    }
}

void GraphGenerator::Pop() { stk_.pop(); }

void GraphGenerator::Save(std::string path) {
    std::ofstream f(path);
    f << "digraph g {" << std::endl;
    for (auto e : edges_) f << "\t" << e << std::endl;
    for (auto n : nodes_) f << "\t" << n << std::endl;
    f << "}";
    f.close();
}