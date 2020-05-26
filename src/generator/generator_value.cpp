#include "generator.h"
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <stdlib.h>

std::shared_ptr<VisitorResult> Generator::VisitASTConstValue(ASTConstValue *node) {
    llvm::Type *tp;
    switch (node->getValueType()) {
        case ASTConstValue::ValueType::INTEGER:
            tp = llvm::Type::getInt32Ty(this->context);
            int v_int = atoi(node->getContent.c_str());
            return std::make_shared<ValueResult>(
                    llvm::ConstantInt::get(tp, (uint64_t) v_int, true)
            );
            break;
        case ASTConstValue::ValueType::FLOAT:
            tp = llvm::Type::getDoubleTy(this->context);
            double v_float = atof(node->getContent.c_str());
            return std::make_shared<ValueResult>(
                    llvm::ConstantFP::get(tp, v_float)
            );
            break;
        case ASTConstValue::ValueType::CHAR:
            tp = llvm::Type::getInt8Ty(this->context);
            char v_int = node->getContent[1];
            return std::make_shared<ValueResult>(
                    llvm::ConstantInt::get(tp, (uint64_t) v_int, true)
            );
            break;
        case ASTConstValue::ValueType::STRING:
            llvm::Value *mem_str = this->builder.CreateGlobalString(
                    node->getContent.substr(1, node->getContent.length() - 2));
            llvm::Value *v_str = this->builder.CreateLoad(mem_str);
            return std::make_shared<ValueResult>(v_str, mem_str);
            break;
        case ASTConstValue::ValueType::BOOL:
            tp = llvm::Type::getInt1Ty(this->context);
            char v_int = node->getContent[1];
            return std::make_shared<ValueResult>(
                    llvm::ConstantInt::get(tp, (uint64_t) v_int, true)
            );
            break;
    }
}

std::shared_ptr<VisitorResult> Generator::VisitASTConstExprList(ASTConstExprList *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTConstExpr(ASTConstExpr *node) {

}

std::shared_ptr<VisitorResult> Generator::VisitASTConstPart(ASTConstPart *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTVarPart(ASTVarPart *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTVarDeclList(ASTVarDeclList *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTVarDecl(ASTVarDecl *node) {}
