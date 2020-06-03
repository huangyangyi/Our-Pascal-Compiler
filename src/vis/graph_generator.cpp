#include <iostream>
#include "ast/ast_value.h"
#include "generator/generator.h"
#include "ast/ast_type.h"
#include "ast/ast_stmt.h"
#include "../visitor.h"
#include "ast/ast_prog.h"
#include <stdlib.h>
#include "graph_generator.h"
#include <fstream>
#include <sstream>
#include <regex>

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

shared_ptr<VisitorResult> GraphGenerator::VisitASTNameList(ASTNameList *node) {
    this->AddNode("name_list", node->line(), node->col());
    for (auto id : node->GetIdentifierList()) {
        this->AddIdentifier(id);
    }
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTExpressionList(ASTExpressionList *node) {
    this->AddNode("expression_list", node->line(), node->col());
    for (auto expr : node->getExprList())
        expr->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTBinaryExpr(ASTBinaryExpr *node) {
    string op_name = node->getOpName(node->getOp());
    this->AddNode(string("binary_op_expr: ") + op_name, node->line(),
                  node->col());
    node->getLExpr()->Accept(this);
    node->getRExpr()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTUnaryExpr(ASTUnaryExpr *node) {
    string op_name;
    switch (node->getOp()) {
        case ASTUnaryExpr::Oper::NOT:
            op_name = "NOT";
            break;
        case ASTUnaryExpr::Oper::SUB:
            op_name = "SUB";
            break;
    }
    this->AddNode(string("unary_op_expr: ") + op_name, node->line(),
                  node->col());
    node->getExpr()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTPropExpr(ASTPropExpr *node) {
    this->AddNode("property_expr:", node->line(), node->col());
    this->AddIdentifier(node->getId());
    this->AddIdentifier(node->getPropId());
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTConstValueExpr(ASTConstValueExpr *node) {
    node->getConstValue()->Accept(this);
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTFuncCall(ASTFuncCall *node) {
    this->AddNode("func_call", node->line(), node->col());
    this->AddIdentifier(node->getFuncId());
    node->getArgList()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTIDExpr(ASTIDExpr *node) {
    this->AddNode("ID_expr", node->line(), node->col());
    this->AddIdentifier(node->getId());
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTArrayExpr(ASTArrayExpr *node) {
    this->AddNode("array_expr", node->line(), node->col());
    this->AddIdentifier(node->getId());
    node->getExpr()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTProgramHead(ASTProgramHead *node) {
    this->AddNode("program_head", node->line(), node->col());
    this->AddIdentifier(node->getId());
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTRoutineHead(ASTRoutineHead *node) {
    this->AddNode("routine_head", node->line(), node->col());
    if (node->getConstPart() != nullptr) node->getConstPart()->Accept(this);
    if (node->getTypePart() != nullptr) node->getTypePart()->Accept(this);
    if (node->getVarPart() != nullptr) node->getVarPart()->Accept(this);
    if (node->getRoutinePart() != nullptr) node->getRoutinePart()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTRoutineBody(ASTRoutineBody *node) {
    this->AddNode("routine_body", node->line(), node->col());
    node->getCompoundStmt()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTRoutine(ASTRoutine *node) {
    this->AddNode("routine", node->line(), node->col());
    node->getRoutineHead()->Accept(this);
    node->getRoutineBody()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTProgram(ASTProgram *node) {
    this->AddNode("program", node->line(), node->col());
    node->getProgramHead()->Accept(this);
    node->getRoutine()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTRoutinePart(ASTRoutinePart *node) {
    this->AddNode("routine_part", node->line(), node->col());
    for (auto fp : node->getRoutineList()) fp->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTFunctionDecl(ASTFunctionDecl *node) {
    this->AddNode("function_decl", node->line(), node->col());
    if (node->getFunctionHead() != nullptr) node->getFunctionHead()->Accept(this);
    if (node->getRoutine() != nullptr) node->getRoutine()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTFunctionHead(ASTFunctionHead *node) {
    this->AddNode("function_head of " + node->getFuncName(), node->line(),
                  node->col());
    if (node->getParameters() != nullptr) node->getParameters()->Accept(this);
    if (node->getSimpleTypeDecl() != nullptr) node->getSimpleTypeDecl()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTProcedureDecl(ASTProcedureDecl *node) {
    this->AddNode("procedure_decl", node->line(), node->col());
    if (node->getProcedureHead() != nullptr) node->getProcedureHead()->Accept(this);
    if (node->getRoutine() != nullptr) node->getRoutine()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTProcedureHead(ASTProcedureHead *node) {
    this->AddNode("procedure_head of " + node->getProcName(), node->line(),
                  node->col());
    if (node->getParameters() != nullptr) node->getParameters()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTParaDeclList(ASTParaDeclList *node) {
    this->AddNode("para_decl_list", node->line(), node->col());
    for (auto type_list : node->getParaDeclList()) type_list->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTParaTypeList(ASTParaTypeList *node) {
    this->AddNode("para_type_list", node->line(), node->col());
    node->getParaList()->Accept(this);
    node->getSimpleTypeDecl()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTVarParaList(ASTVarParaList *node) {
    this->AddNode("var_para_list", node->line(), node->col());
    node->getNameList()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTValParaList(ASTValParaList *node) {
    this->AddNode("val_para_list", node->line(), node->col());
    node->getNameList()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTStmtList(ASTStmtList *node) {
    this->AddNode("stmt_list", node->line(), node->col());
    for (int i = 0; i < node->getStmtList().size(); i++) node->getStmtList()[i]->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTStmt(ASTStmt *node) {
    if (node->getLabel() == "") {
        node->getNonLabelStmt()->Accept(this);
    } else {
        this->AddNode("node->getLabel()stmt " + node->getLabel(), node->line(), node->col());
        node->getNonLabelStmt()->Accept(this);
        this->Pop();
    }
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTAssignStmt(ASTAssignStmt *node) {
    this->AddNode("assign_stmt", node->line(), node->col());
    node->getExpr1()->Accept(this);
    node->getExpr2()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTProcStmt(ASTProcStmt *node) {
    this->AddNode("proc_stmt", node->line(), node->col());
    this->AddIdentifier(node->getId());
    if (node->getExprList() != nullptr) node->getExprList()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTIfStmt(ASTIfStmt *node) {
    this->AddNode("if_stmt", node->line(), node->col());
    node->getExpr()->Accept(this);
    node->getStmt()->Accept(this);
    if (node->getElseClause() != nullptr) node->getElseClause()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTElseClause(ASTElseClause *node) {
    this->AddNode("else_clause", node->line(), node->col());
    node->getStmt()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTRepeatStmt(ASTRepeatStmt *node) {
    this->AddNode("repeat_stmt", node->line(), node->col());
    node->getStmtList()->Accept(this);
    node->getExpr()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTWhileStmt(ASTWhileStmt *node) {
    this->AddNode("while_stmt", node->line(), node->col());
    node->getExpr()->Accept(this);
    node->getStmt()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTForStmt(ASTForStmt *node) {
    string dir_name;
    switch (node->getDir()) {
        case ASTForStmt::ForDir::TO:
            dir_name = "TO";
            break;
        case ASTForStmt::ForDir::DOWNTO:
            dir_name = "DOWNTO";
            break;
    }
    this->AddNode(string("for_stmt: ") + dir_name, node->line(), node->col());
    this->AddIdentifier(node->getId());
    node->getForExpr()->Accept(this);
    node->getToExpr()->Accept(this);
    node->getStmt()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTCaseStmt(ASTCaseStmt *node) {
    this->AddNode("case_stmt", node->line(), node->col());
    node->getExpr()->Accept(this);
    node->getCaseExprList()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTCaseExprList(ASTCaseExprList *node) {
    this->AddNode("case_expr_list", node->line(), node->col());
    for (auto expr : node->getCaseExprList()) expr->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTCaseExpr(ASTCaseExpr *node) {
    this->AddNode("case_expr", node->line(), node->col());
    node->getExpr()->Accept(this);
    node->getStmt()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTGotoStmt(ASTGotoStmt *node) {
    stringstream ss;
    ss << "goto_stmt: " << node->getLabel();
    this->AddNode(ss.str(), node->line(), node->col());
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTExitStmt(ASTExitStmt *node) {
    this->AddNode("exit", node->line(), node->col());
    if (node->getExpr()) node->getExpr()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTBreakStmt(ASTBreakStmt *node) {
    this->AddNode("break", node->line(), node->col());
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTType(ASTType *node) {
    // Need to be considered more...
    switch (node->getTypeName()) {
        case ASTType::TypeName::INTEGER:
            this->AddIdentifier("Integer");
            break;
        case ASTType::TypeName::REAL:
            this->AddIdentifier("Real");
            break;
        case ASTType::TypeName::BOOLEAN:
            this->AddIdentifier("Boolean");
            break;
        case ASTType::TypeName::CHAR:
            this->AddIdentifier("Char");
            break;
        case ASTType::TypeName::STRING:
            this->AddIdentifier("String");
            break;
    }
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTSimpleTypeDecl(ASTSimpleTypeDecl *node) {
    this->AddNode("simple_type_decl", node->line(), node->col());
    if (node->getTypeName()) node->getTypeName()->Accept(this);
    else this->AddIdentifier(node->getDefinedId());
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTArrayTypeDecl(ASTArrayTypeDecl *node) {
    this->AddNode("array_type_decl", node->line(), node->col());
    node->getSimpleTypeDecl()->Accept(this);
    node->getTypeDecl()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTFieldDecl(ASTFieldDecl *node) {
    this->AddNode("field_decl", node->line(), node->col());
    node->getNameList()->Accept(this);
    node->getTypeDecl()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTFieldDeclList(ASTFieldDeclList *node) {
    this->AddNode("field_decl_list", node->line(), node->col());
    for (int i = 0; i < (int) node->getFielddeclList().size(); i++)
        node->getFielddeclList()[i]->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTRecordTypeDecl(ASTRecordTypeDecl *node) {
    this->AddNode("file_decl_list", node->line(), node->col());
    node->getFieldDeclList()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTTypePart(ASTTypePart *node) {
    this->AddNode("type_part", node->line(), node->col());
    node->getTypeDeclList()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTTypeDefinition(ASTTypeDefinition *node) {
    this->AddNode("type_definition", node->line(), node->col());
    this->AddIdentifier(node->getId());
    node->getTypeDecl()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTTypeDeclList(ASTTypeDeclList *node) {
    this->AddNode("type_decl_list", node->line(), node->col());
    for (auto defi: node->getTypeList()) {
        defi->Accept(this);
    }
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTConstValue(ASTConstValue *node) {
    string value_type_name = node->getValueTypeName(node->getValueType());
    this->AddValue(value_type_name, node->getContent());
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTConstPart(ASTConstPart *node) {
    this->AddNode("const_part", node->line(), node->col());
    node->getConstExprList()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTConstExprList(ASTConstExprList *node) {
    this->AddNode("const_expr_list", node->line(), node->col());
    for (auto expr: node->getConstExprList()) expr->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTConstExpr(ASTConstExpr *node) {
    this->AddNode("const_expr", node->line(), node->col());
    this->AddIdentifier(node->getId());
    node->getValue()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTVarPart(ASTVarPart *node) {
    this->AddNode("var_part:", node->line(), node->col());
    node->getVarDeclList()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTVarDeclList(ASTVarDeclList *node) {
    this->AddNode("var_decl_list:", node->line(), node->col());
    for (int i = 0; i < (int) node->getVarDeclList().size(); i++)
        node->getVarDeclList()[i]->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTVarDecl(ASTVarDecl *node) {
    this->AddNode("Var_decl:", node->line(), node->col());
    node->getNameList()->Accept(this);
    node->getTypeDecl()->Accept(this);
    this->Pop();
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTFuncProcBase(ASTFuncProcBase *node) {
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTNode(ASTNode *node) {
    return nullptr;
}

shared_ptr<VisitorResult> GraphGenerator::VisitASTNonLabelStmt(ASTNonLabelStmt *node) {
    return nullptr;
}
