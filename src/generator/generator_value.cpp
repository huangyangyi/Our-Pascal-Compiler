#include "generator.h"
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/GlobalValue.h>
#include <llvm/IR/GlobalVariable.h>
#include <stdlib.h>
#include "generator_result.hpp"


std::shared_ptr<VisitorResult> Generator::VisitASTConstValue(ASTConstValue *node) {
    llvm::Type *tp;
    if (node->getValueType() == ASTConstValue::ValueType::INTEGER) {
        tp = llvm::Type::getInt32Ty(this->context);
        int v_int = atoi(node->getContent().c_str());
        return std::make_shared<ValueResult>(
                OurType::INT_TYPE,
                llvm::ConstantInt::get(tp, (uint64_t) v_int, true),
                nullptr
        );
    }
    if (node->getValueType() == ASTConstValue::ValueType::FLOAT) {
        
        tp = llvm::Type::getDoubleTy(this->context);
        
        double v_float = atof(node->getContent().c_str());
        std::cout << v_float << std::endl;
        return std::make_shared<ValueResult>(
                OurType::REAL_TYPE,
                llvm::ConstantFP::get(tp, v_float),
                nullptr
        );
    }
    if (node->getValueType() == ASTConstValue::ValueType::CHAR) {
        tp = llvm::Type::getInt8Ty(this->context);
        char v_int = node->getContent()[1];
        return std::make_shared<ValueResult>(
                OurType::CHAR_TYPE,
                llvm::ConstantInt::get(tp, (uint64_t) v_int, true),
                nullptr
        );
    }
    if (node->getValueType() == ASTConstValue::ValueType::STRING) {
        // to make str things can store, alloc with each other
        // we have to make all string values have the same length
        // we make this 256
        // so we add suffix zero to all constant string
        // VERY BAD CODING STYLE
        // NEED TO BE MODIFIED ASAP
        std::string tmp = node->getContent().substr(1, node->getContent().length() - 2);
        int tmp_len = tmp.size();
        if (tmp_len > 255) {
            std::cerr << node->get_location() << "this string constant is too long, use first 255 characters instead." << std::endl;
            //This is not error but just warning. Maybe we can add a 'warning type' to report all warnings.
            tmp = tmp.substr(0, 255);
            tmp_len = tmp.size();
        }
        char zero = 0;
        for (int i = 0; i < 255 - tmp_len; i++) tmp = tmp + zero;
        llvm::Value *mem_str = this->builder.CreateGlobalString(tmp);
        llvm::Value *v_str = this->builder.CreateLoad(mem_str);
        return std::make_shared<ValueResult>(
                new OurType::StrType(),
                v_str,
                mem_str
        );
    }
    if (node->getValueType() == ASTConstValue::ValueType::BOOL) {
        tp = llvm::Type::getInt1Ty(this->context);
        std::string lit = node->getContent();
        for (int i=0;i < lit.length(); i++) lit[i] = tolower(lit[i]);
        bool p = lit == "true" ? true : false;
        return std::make_shared<ValueResult>(
                OurType::BOOLEAN_TYPE,
                llvm::ConstantInt::get(tp, (uint64_t) p, true),
                nullptr
        );
    }
    const PascalType *ty = BOOLEAN_TYPE;
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTConstExprList(ASTConstExprList *node) {
    for (auto expr: node->getConstExprList()) expr->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTConstExpr(ASTConstExpr *node) {
    std::shared_ptr<ValueResult> res = std::static_pointer_cast<ValueResult>(node->getValue()->Accept(this));
    llvm::GlobalVariable *constant = new llvm::GlobalVariable(
            /*Module=*/*(this->module),
            /*Type=*/OurType::getLLVMType(this->context, res->getType()),
            /*isConstant=*/true,
            /*Linkage=*/llvm::GlobalValue::CommonLinkage,
            /*Initializer=*/(llvm::Constant *) res->getValue(), // has initializer, specified below
            /*Name=*/node->getId());
    if (this->block_stack.back()->named_values.count(node->getId()) || this->named_constants.count(node->getId())) {
        //error 
    }
    this->named_constants[node->getId()] = (llvm::Constant *) (res->getValue());
    this->block_stack[0]->named_values[node->getId()] = constant;
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTConstPart(ASTConstPart *node) {
    return node->getConstExprList()->Accept(this);
}

std::shared_ptr<VisitorResult> Generator::VisitASTVarPart(ASTVarPart *node) {
    return node->getVarDeclList()->Accept(this);
}

std::shared_ptr<VisitorResult> Generator::VisitASTVarDeclList(ASTVarDeclList *node) {
    for (auto expr: node->getVarDeclList())
        expr->Accept(this);
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTVarDecl(ASTVarDecl *node) {
    auto res = std::static_pointer_cast<TypeResult>(node->getTypeDecl()->Accept(this));
    auto name_list = std::static_pointer_cast<NameList>(node->getNameList()->Accept(this));
    if (res == nullptr) return nullptr; //The error has been reported.
    for (auto id: name_list->getNameList()) {
        llvm::Type *ty = OurType::getLLVMType(this->context, res->getType());
        if (this->block_stack.size() == 1) {
            llvm::Constant * initializer;
            if (res->getType()->isBuiltInTy()) initializer = llvm::Constant::getNullValue(ty);
            else initializer = llvm::ConstantAggregateZero::get(ty);
            llvm::GlobalVariable *var = new llvm::GlobalVariable(
                    /*Module=*/*(this->module),
                    /*Type=*/ty,
                    /*isConstant=*/false,
                    /*Linkage=*/llvm::GlobalValue::CommonLinkage,
                    /*Initializer=*/initializer, // has initializer, specified below
                    /*Name=*/id);
            if (this->block_stack.back()->named_values.count(id)) {
                //error 
            }
            this->block_stack.back()->named_values[id] = var;
            this->block_stack.back()->named_types[id] = res->getType();
        } else {
            llvm::AllocaInst *var = this->builder.CreateAlloca(
                    ty,
                    nullptr,
                    id
            );
            if (this->block_stack.back()->named_values.count(id)) {
                //error 
            }
            this->block_stack.back()->named_values[id] = var;
            this->block_stack.back()->named_types[id] = res->getType();
        }
    }
    return nullptr;
}
