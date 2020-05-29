#include "generator.h"
#include "generator_result.hpp"
#include <llvm/IR/Function.h>
#include <iostream>

using namespace OurType;

std::shared_ptr<VisitorResult> Generator::VisitASTNonLabelStmt(ASTNonLabelStmt *node) {
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTStmt(ASTStmt *node) {
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();    
    auto label_block = llvm::BasicBlock::Create(this->context, "label_" + node->getLabel(), func);
    this->builder.CreateBr(label_block);
    this->builder.SetInsertPoint(label_block);
    node->getNonLabelStmt()->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTStmtList(ASTStmtList *node) {
    for (auto stmt: node->getStmtList()) stmt->Accept(this);
    return nullptr;
}

llvm::Value* Generator::genMatch(llvm::Value* dest, PascalType *dest_type, llvm::Value* src, PascalType *src_type) {
    if (!isEqual(dest_type, src_type)) {
        //error here
        return nullptr;
    }
    if (dest_type->isIntegerTy()) {
        return this->builder.CreateICmpEQ(dest, src);
    }
    else if (dest_type->isStringTy()) {
        return nullptr;//TODO: implement string match
    }
    else if (dest_type->isCharTy()) {
        return this->builder.CreateICmpEQ(dest, src);
    }
}

void Generator::genAssign(llvm::Value* dest_ptr, PascalType *dest_type, llvm::Value* src, PascalType *src_type) {
    if (!isEqual(dest_type, src_type)) {
        //Type conversions
        if (src_type->isIntegerTy() && dest_type->isFloatingPointTy()) {
            src = this->builder.CreateSIToFP(src, llvm::Type::getFloatTy(this->context));
            this->builder.CreateStore(src, dest_ptr);
        }
    }
    else if (dest_type->isSimple()) {
        this->builder.CreateStore(src, dest_ptr);
    }
    else if (dest_type->isStringTy()) {
        this->builder.CreateStore(src, dest_ptr)
        //TODO: implement string assignment
    }
    else if (dest_type->isArrayTy()) {
        //TODO: implement array assignment
    }
    else if (dest_type->isRecordTy()) {
        //TODO: implement record assignment
    }
}

std::shared_ptr<VisitorResult> Generator::VisitASTAssignStmt(ASTAssignStmt *node) {
    auto left = std::static_pointer_cast<ValueResult>(node->getExpr1()->Accept(this));
    auto right = std::static_pointer_cast<ValueResult>(node->getExpr2()->Accept(this));
    if (left == nullptr || right == nullptr) return nullptr;
    if (left->getMem() == nullptr) {
        std::cerr << "Invalid left expression" << endl;//not left expression error
        return nullptr;
    }
    genAssign(left->getMem(), left->getType(), right->getValue(), right->getType());
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTProcStmt(ASTProcStmt *node) {
    auto arg_list_res = std::static_pointer_cast<ValueListResult>(node->getExprList()->Accept(this));
    this->genFuncCall(node->getId(), arg_list_res->getValueList());
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTIfStmt(ASTIfStmt *node) {
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *then_block = llvm::BasicBlock::Create(this->context, "if_then", func);
    llvm::BasicBlock *else_block = llvm::BasicBlock::Create(this->context, "if_else", func);
    llvm::BasicBlock *cont_block = llvm::BasicBlock::Create(this->context, "if_cont", func);
    auto cond_res = std::static_pointer_cast<ValueResult>(node->getExpr()->Accept());
    if (cond_res == nullptr) return nullptr;
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

    this->builder.CreateBr(body_block);
    this->builder.SetInsertPoint(body_block);

    node->getStmtList()->Accept(this);

    this->builder.CreateBr(cond_block);
    this->builder.SetInsertPoint(cond_block);

    auto cond_res = std::static_pointer_cast<ValueResult>(node->getExpr()->Accept(this));
    if (cond_res == nullptr) return nullptr;
    if (!cond_res->getValue()->getType()->isIntegerTy(1)) {
        //ERROR: Not boolean expression
    };

    this->builder.CreateCondBr(cond_res->getValue(), cont_block, body_block);
    this->builder.SetInsertPoint(cont_block);

    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTWhileStmt(ASTWhileStmt *node) {
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *cond_block = llvm::BasicBlock::Create(this->context, "while_cond", func);
    llvm::BasicBlock *body_block = llvm::BasicBlock::Create(this->context, "while_body", func);
    llvm::BasicBlock *end_block = llvm::BasicBlock::Create(this->context, "while_end", func);
    
    this->builder.CreateBr(cond_block);
    this->builder.SetInsertPoint(cond_block);

    auto cond_res = std::static_pointer_cast<ValueResult>(node->getExpr()->Accept(this));
    if (cond_res == nullptr) return nullptr;
    this->builder.CreateCondBr(cond_res->getValue(), body_block, end_block);
    this->builder.SetInsertPoint(body_block);
    node->getStmt()->Accept(this);
    
    this->builder.CreateBr(cond_block);
    this->builder.SetInsertPoint(end_block);
    
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTForStmt(ASTForStmt *node) {
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *start_block = llvm::BasicBlock::Create(this->context, "for_start", func);
    llvm::BasicBlock *body_block = llvm::BasicBlock::Create(this->context, "for_body", func);
    llvm::BasicBlock *cond_block = llvm::BasicBlock::Create(this->context, "for_cond", func);
    llvm::BasicBlock *end_block = llvm::BasicBlock::Create(this->context, "for_end", func);
    builder.CreateBr(start_block);
    builder.SetInsertPoint(start_block);
    auto st = std::static_pointer_cast<ValueResult>(node->getForExpr()->Accept(this));
    if (st == nullptr) return nullptr;
    llvm::Value *iter = this->block_stack.back()->named_values[node->getId()];
    //check type here
    this->builder.CreateStore(st->getValue(), iter);
    this->builder.CreateBr(body_block);
    this->builder.SetInsertPoint(body_block);
    node->getStmt()->Accept(this);

    this->builder.CreateBr(cond_block);
    this->builder.SetInsertPoint(cond_block);
    auto en = std::static_pointer_cast<ValueResult>(node->getToExpr()->Accept(this));
    if (en == nullptr) return nullptr;
    int step = node->getDir() == ASTForStmt::ForDir::TO ? 1 : -1;
    llvm::Constant *step_const = llvm::ConstantInt::get(en->getValue()->getType(), step, true);
    llvm::Value *iter_res = this->builder.CreateLoad(iter);
    iter_res = this->builder.CreateAdd(iter_res, step_const);
    this->builder.CreateStore(iter_res, iter);
    llvm::Value *cmp_res = node->getDir() == ASTForStmt::ForDir::TO ? this->builder.CreateICmpSGT(iter_res, en->getValue()) : this->builder.CreateICmpSLT(iter_res, en->getValue());

    this->builder.CreateCondBr(cmp_res, end_block, body_block);
    this->builder.SetInsertPoint(end_block);
    
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTCaseStmt(ASTCaseStmt *node) {
    llvm::Function *func = this->builder.GetInsertBlock()->getParent();
    auto case_expr_list = node->getCaseExprList()->getCaseExprList();
    auto expr_res = node->getExpr()->Accept(this);
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
        auto cond_res = static_pointer_cast<ValueResult>(case_expr->getExpr()->Accept(this));
        auto match_res = genMatch(cond_res->getValue(), cond_res->getType(), expr_res->getValue(), expr_res->getType());
        this->builder.CreateCondBr(match_res, body_vec[i], i == len - 1 ? end_block : cond_vec[i+1]);
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
    this->builder.CreateBr(target_block);
    return nullptr;
}