#include "generator.h"
#include "generator_result.hpp"
#include <llvm/IR/Function.h>
#include <iostream>
#include <stdlib.h>

using namespace OurType;

std::shared_ptr<VisitorResult> Generator::VisitASTNonLabelStmt(ASTNonLabelStmt *node) {
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTStmt(ASTStmt *node) {
    if (node->getLabel() != "") {
        int label = atoi(node->getLabel().c_str());
        if (this->getCurrentBlock()->labels.count(label) > 0){
            this->RecordErrorMessage("Duplicated label: " + node->getLabel(), node->get_location_pairs());
        } else {
            llvm::Function *func = this->builder.GetInsertBlock()->getParent();
            auto label_block = llvm::BasicBlock::Create(this->context, "label_" + node->getLabel(), func);
            this->builder.CreateBr(label_block);
            this->builder.SetInsertPoint(label_block);
            this->getCurrentBlock()->labels[label] = label_block;
        }
    }
    node->getNonLabelStmt()->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTStmtList(ASTStmtList *node) {
    for (auto stmt: node->getStmtList()) stmt->Accept(this);
    return nullptr;
}

void Generator::genAssign(llvm::Value* dest_ptr, PascalType *dest_type, llvm::Value* src, PascalType *src_type) {
    if (dest_type->isSimple()) {
        if (!isEqual(dest_type, src_type)) {
            //Type conversions
            if (src_type->isIntegerTy() && dest_type->isFloatingPointTy()) {
                src = this->builder.CreateSIToFP(src, llvm::Type::getFloatTy(this->context));
                this->builder.CreateStore(src, dest_ptr);
            }
        }
        else this->builder.CreateStore(src, dest_ptr);
    }
    else if (dest_type->isStringTy()) {
        this->builder.CreateStore(src, dest_ptr);
    }
    else if (dest_type->isArrayTy()) {
        this->builder.CreateStore(src, dest_ptr);
        //TODO: implement array assignment
    }
    else if (dest_type->isRecordTy()) {
        this->builder.CreateStore(src, dest_ptr);
        //TODO: implement record assignment
    }
}

std::shared_ptr<VisitorResult> Generator::VisitASTAssignStmt(ASTAssignStmt *node) {
    std::cout << "assign!" << std::endl;
    auto left = std::static_pointer_cast<ValueResult>(node->getExpr1()->Accept(this));
    auto right = std::static_pointer_cast<ValueResult>(node->getExpr2()->Accept(this));
    if (left == nullptr || right == nullptr) return nullptr;
    if (left->getMem() == nullptr) 
        return RecordErrorMessage("Invalid left expression.", node->get_location_pairs());
    genAssign(left->getMem(), left->getType(), right->getValue(), right->getType());
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTProcStmt(ASTProcStmt *node) {
    ASTFuncCall *ast_func = new ASTFuncCall(node->getId(), node->getExprList());
    auto res = ast_func->Accept(this);
    delete ast_func;
    return res;
}

std::shared_ptr<VisitorResult> Generator::VisitASTIfStmt(ASTIfStmt *node) {
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *then_block = llvm::BasicBlock::Create(this->context, "if_then", func);
    llvm::BasicBlock *else_block = llvm::BasicBlock::Create(this->context, "if_else", func);
    llvm::BasicBlock *cont_block = llvm::BasicBlock::Create(this->context, "if_cont", func);
    auto cond_res = std::static_pointer_cast<ValueResult>(node->getExpr()->Accept(this));
    if (cond_res == nullptr || !isEqual(cond_res->getType(), BOOLEAN_TYPE))
        return RecordErrorMessage("Invalid condition in if statement.", node->get_location_pairs());
    this->builder.CreateCondBr(cond_res->getValue(), then_block, else_block);
    this->builder.SetInsertPoint(then_block);
    node->getStmt()->Accept(this);
    this->builder.CreateBr(cont_block);
    this->builder.SetInsertPoint(else_block);
    if (node->getElseClause() != nullptr) {
        node->getElseClause()->Accept(this);
    }
    this->builder.CreateBr(cont_block);
    this->builder.SetInsertPoint(cont_block);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTElseClause(ASTElseClause *node) {
    return node->getStmt()->Accept(this);
}

std::shared_ptr<VisitorResult> Generator::VisitASTRepeatStmt(ASTRepeatStmt *node) {
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *body_block = llvm::BasicBlock::Create(this->context, "repeat_body", func);
    llvm::BasicBlock *cond_block = llvm::BasicBlock::Create(this->context, "repeat_cond", func);
    llvm::BasicBlock *cont_block = llvm::BasicBlock::Create(this->context, "repeat_cont", func);
    this->getCurrentBlock()->loop_breaks.push_back(cont_block);

    this->builder.CreateBr(body_block);
    this->builder.SetInsertPoint(body_block);

    node->getStmtList()->Accept(this);

    this->builder.CreateBr(cond_block);
    this->builder.SetInsertPoint(cond_block);
    auto cond_res = std::static_pointer_cast<ValueResult>(node->getExpr()->Accept(this));

    //#if (!cond_res->getValue()->getType()->isIntegerTy(1))
    if (cond_res == nullptr || !isEqual(cond_res->getType(), BOOLEAN_TYPE))
        return RecordErrorMessage("Invalid condition in repeat statement.", node->get_location_pairs());

    this->builder.CreateCondBr(cond_res->getValue(), cont_block, body_block);
    this->builder.SetInsertPoint(cont_block);

    this->getCurrentBlock()->loop_breaks.pop_back();
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTWhileStmt(ASTWhileStmt *node) {
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *cond_block = llvm::BasicBlock::Create(this->context, "while_cond", func);
    llvm::BasicBlock *body_block = llvm::BasicBlock::Create(this->context, "while_body", func);
    llvm::BasicBlock *end_block = llvm::BasicBlock::Create(this->context, "while_end", func);
    this->getCurrentBlock()->loop_breaks.push_back(end_block);

    this->builder.CreateBr(cond_block);
    this->builder.SetInsertPoint(cond_block);

    auto cond_res = std::static_pointer_cast<ValueResult>(node->getExpr()->Accept(this));
    if (cond_res == nullptr || !isEqual(cond_res->getType(), BOOLEAN_TYPE))
        return RecordErrorMessage("Invalid condition in while statement.", node->get_location_pairs());
    
    this->builder.CreateCondBr(cond_res->getValue(), body_block, end_block);
    this->builder.SetInsertPoint(body_block);
    node->getStmt()->Accept(this);
    
    this->builder.CreateBr(cond_block);
    this->builder.SetInsertPoint(end_block);

    this->getCurrentBlock()->loop_breaks.pop_back();
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTForStmt(ASTForStmt *node) {
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *start_block = llvm::BasicBlock::Create(this->context, "for_start", func);
    llvm::BasicBlock *body_block = llvm::BasicBlock::Create(this->context, "for_body", func);
    llvm::BasicBlock *cond_block = llvm::BasicBlock::Create(this->context, "for_cond", func);
    llvm::BasicBlock *step_back_block = llvm::BasicBlock::Create(this->context, "for_step_back", func);
    llvm::BasicBlock *end_block = llvm::BasicBlock::Create(this->context, "for_end", func);
    this->getCurrentBlock()->loop_breaks.push_back(end_block);

    builder.CreateBr(start_block);
    builder.SetInsertPoint(start_block);

    auto ast_id_expr = new ASTIDExpr(node->getId());
    auto ast_assign = new ASTAssignStmt(ast_id_expr, node->getForExpr());
    ast_assign->Accept(this);
    auto ast_st_cmp = new ASTBinaryExpr(
            node->getDir() == ASTForStmt::ForDir::TO ? ASTBinaryExpr::Oper::GT : ASTBinaryExpr::Oper::LT,
            ast_id_expr,
            node->getToExpr()
    );
    auto st_cmp_res = std::static_pointer_cast<ValueResult>(ast_st_cmp->Accept(this));
    this->builder.CreateCondBr(st_cmp_res->getValue(), end_block, body_block);
    this->builder.SetInsertPoint(body_block);
    node->getStmt()->Accept(this);

    this->builder.CreateBr(cond_block);
    this->builder.SetInsertPoint(cond_block);
    std::string step = node->getDir() == ASTForStmt::ForDir::TO ? "1" : "-1";

    auto ast_const_value = new ASTConstValue(step, ASTConstValue::ValueType::INTEGER);
    auto ast_const_value_expr = new ASTConstValueExpr(ast_const_value);
    auto ast_step_add = new ASTBinaryExpr(ASTBinaryExpr::Oper::PLUS, ast_id_expr, ast_const_value_expr);
    auto ast_step_assign = new ASTAssignStmt(ast_id_expr, ast_step_add);
    ast_step_assign->Accept(this);

    auto ast_step_cmp = new ASTBinaryExpr(
        node->getDir() == ASTForStmt::ForDir::TO ? ASTBinaryExpr::Oper::GT : ASTBinaryExpr::Oper::LT,
        ast_id_expr,
        node->getToExpr()
    );

    auto cmp_res = std::static_pointer_cast<ValueResult>(ast_step_cmp->Accept(this));
    this->builder.CreateCondBr(cmp_res->getValue(), step_back_block, body_block);
    this->builder.SetInsertPoint(step_back_block);
    auto ast_end_sub = new ASTBinaryExpr(ASTBinaryExpr::Oper::MINUS, ast_id_expr, ast_const_value_expr);
    auto ast_end_assign = new ASTAssignStmt(ast_id_expr, ast_end_sub);
    ast_end_assign->Accept(this);
    this->builder.CreateBr(end_block);
    this->builder.SetInsertPoint(end_block);

    this->getCurrentBlock()->loop_breaks.pop_back();

    delete ast_id_expr;
    delete ast_assign;
    delete ast_const_value;
    delete ast_const_value_expr;
    delete ast_step_add;
    delete ast_step_assign;
    delete ast_step_cmp;
    delete ast_end_sub;
    delete ast_end_assign;

    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTCaseStmt(ASTCaseStmt *node) {
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();
    auto case_expr_list = node->getCaseExprList()->getCaseExprList();
    std::vector<llvm::BasicBlock *> cond_vec;
    std::vector<llvm::BasicBlock *> body_vec;
    int len = case_expr_list.size();
    for (int i=0; i < len; i++) {
        cond_vec.push_back(llvm::BasicBlock::Create(this->context, "case_branch", func));
        body_vec.push_back(llvm::BasicBlock::Create(this->context, "case_body", func));
    }
    auto end_block = llvm::BasicBlock::Create(this->context, "case_end", func);
    this->builder.CreateBr(len == 0 ? end_block : cond_vec[0]);
    for (int i=0; i < len; i++) {
        auto case_expr = case_expr_list[i];
        this->builder.SetInsertPoint(cond_vec[i]);
        auto ast_cmp = new ASTBinaryExpr(ASTBinaryExpr::Oper::EQUAL, node->getExpr(), case_expr->getExpr());
        auto match_res = std::static_pointer_cast<ValueResult>(ast_cmp->Accept(this));
        delete ast_cmp;
        this->builder.CreateCondBr(match_res->getValue(), body_vec[i], i == len - 1 ? end_block : cond_vec[i+1]);
        this->builder.SetInsertPoint(body_vec[i]);
        case_expr->getStmt()->Accept(this);
    }

    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTCaseExprList(ASTCaseExprList *node) {
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTCaseExpr(ASTCaseExpr *node) {
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTGotoStmt(ASTGotoStmt *node) {
    auto target_block = this->block_stack.back()->labels[atoi(node->getLabel().c_str())];
    std::cout<< atoi(node->getLabel().c_str()) << std::endl;
    this->builder.CreateBr(target_block);
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *cont_block = llvm::BasicBlock::Create(this->context, "goto_cont", func);
    this->builder.SetInsertPoint(cont_block);
    return nullptr;
}

shared_ptr<VisitorResult> Generator::VisitASTExitStmt(ASTExitStmt *node) {
    std::shared_ptr<ValueResult> res;
    if (node->getExpr() == nullptr) {
        if (this->block_stack.size() == 1) {//is global
            this->builder.CreateRet(llvm::ConstantInt::get(llvm::Type::getInt32Ty(this->context), 0));
        }
        else if (!this->getCurrentBlock()->is_function) {
            this->builder.CreateRetVoid();
        }
        else {
            llvm::Value* ret = this->builder.CreateLoad(this->getCurrentBlock()->named_values[this->getCurrentBlock()->block_name], "ret");
            this->builder.CreateRet(ret);
        }
    }
    else {
        res = static_pointer_cast<ValueResult>(node->getExpr()->Accept(this));
        this->builder.CreateRet(res->getValue());
    }
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *cont_block = llvm::BasicBlock::Create(this->context, "exit_cont", func);
    this->builder.SetInsertPoint(cont_block);
    return nullptr;
}

shared_ptr<VisitorResult> Generator::VisitASTBreakStmt(ASTBreakStmt *node) {
    if (this->getCurrentBlock()->loop_breaks.empty()) {
        this->RecordErrorMessage("Cannot use break statement out of loops", node->get_location_pairs());
        return nullptr;
    }
    this->builder.CreateBr(this->getCurrentBlock()->loop_breaks.back());
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *cont_block = llvm::BasicBlock::Create(this->context, "break_cont", func);
    this->builder.SetInsertPoint(cont_block);
    return nullptr;
}
