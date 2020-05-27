#include "generator.h"
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/GlobalVariable.h>
#include <stdlib.h>
#include "generator_result.hpp"

std::shared_ptr<VisitorResult> Generator::VisitASTConstValue(ASTConstValue *node) {
    llvm::Type *tp;
    switch (node->getValueType()) {
        case ASTConstValue::ValueType::INTEGER:
            tp = llvm::Type::getInt32Ty(this->context);
            int v_int = atoi(node->getContent().c_str());
            return std::make_shared<ValueResult>(
                    &PascalType::INT_TYPE,
                    llvm::ConstantInt::get(tp, (uint64_t) v_int, true),
                    nullptr
            );
            break;
        case ASTConstValue::ValueType::FLOAT:
            tp = llvm::Type::getDoubleTy(this->context);
            double v_float = atof(node->getContent().c_str());
            return std::make_shared<ValueResult>(
                    &PascalType::REAL_TYPE,
                    llvm::ConstantFP::get(tp, v_float),
                    nullptr
            );
            break;
        case ASTConstValue::ValueType::CHAR:
            tp = llvm::Type::getInt8Ty(this->context);
            char v_int = node->getContent()[1];
            return std::make_shared<ValueResult>(
                    &PascalType::CHAR_TYPE,
                    llvm::ConstantInt::get(tp, (uint64_t) v_int, true),
                    nullptr
            );
            break;
        case ASTConstValue::ValueType::STRING:
            llvm::Value *mem_str = this->builder.CreateGlobalString(
                    new PascalType::StrType(),
                    node->getContent.substr(1, node->getContent.length() - 2));
            llvm::Value *v_str = this->builder.CreateLoad(mem_str);
            return std::make_shared<ValueResult>(v_str, mem_str);
            break;
        case ASTConstValue::ValueType::BOOL:
            tp = llvm::Type::getInt1Ty(this->context);
            char v_int = node->getContent[1];
            return std::make_shared<ValueResult>(
                    llvm::ConstantInt::get(tp, (uint64_t) v_int, true),
                    nullptr
            );
            break;
    }
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTConstExprList(ASTConstExprList *node) {
    for (auto expr: node->getConstExprList()) expr->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTConstExpr(ASTConstExpr *node) {
    auto res = std::static_pointer_cast<ValueResult> (node->getValue()->Accept(this));
    llvm::GlobalVariable *constant = new llvm::GlobalVariable(
        /*Module=*/*(this->module), 
        /*Type=*/llvm::Type(this->context, res->getTypeId()),
        /*isConstant=*/true,
        /*Linkage=*/llvm::GlobalValue::CommonLinkage,
        /*Initializer=*/res->getValue(), // has initializer, specified below
        /*Name=*/node->getId());
    
    this->block_stack.back()->named_values.insert(node->getId(), constant);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTConstPart(ASTConstPart *node) {
    return node->getConstExprList()->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTVarPart(ASTVarPart *node) {
    return node->getVarDeclList()->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTVarDeclList(ASTVarDeclList *node) {
    for (auto expr: node->getVarDeclList()) expr->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTVarDecl(ASTVarDecl *node) {
    auto res = std::static_pointer_cast<> (node->getTypeDecl()->Accept(this));
    auto name_list = std::static_pointer_cast<NameList> (node->getNameList()->Accept(this));

    for (auto id: name_list->get_list()) {
        if (this->block_stack.size() == 1) {
            llvm::GlobalVariable *var = new llvm::GlobalVariable(
            /*Module=*/*(this->module), 
            /*Type=*/llvm::Type(this->context, res->getTypeId()),
            /*isConstant=*/false,
            /*Linkage=*/llvm::GlobalValue::CommonLinkage,
            /*Initializer=*/0, // has initializer, specified below
            /*Name=*/id);
            this->block_stack.back()->named_values[id] = var;
        } else {
            llvm::AllocInst *var = this->builder.CreateAlloca(); 
        }
    }

    return nullptr;
}
