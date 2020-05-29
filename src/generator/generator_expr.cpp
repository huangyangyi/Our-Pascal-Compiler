#include "generator.h"
#include "generator_result.hpp"
#include "../ast/ast_expr.h"
#include <llvm/IR/Value.h>
#include <llvm/IR/Type.h>

using namespace OurType;

std::shared_ptr<VisitorResult> Generator::VisitASTExpressionList(ASTExpressionList *node) {
    auto expr_list = node->getExprList();
    std::vector<ValueResult*> ret;
    for (auto expr_node: expr_list){
        ValueResult* val = static_pointer_cast<ValueResult>(expr_node->Accept(this));
        if (val == nullptr) return nullptr;
        ret.push_back(val);
    }
    return std::make_shared<ValueListResult>(ret);
}

#define Op(x) ASTBinaryExpr::Oper::x

bool check_arith(PascalType *l, PascalType *r, PascalType *ret){
    if (!l->isSimple() || !r->isSimple()) return false;
    // Don't consider the string temporarily.
    if (isEqual(l, BOOLEAN_TYPE) || isEqual(r, BOOLEAN_TYPE)) return false;
    //boolean type can not take part in the arithmetic
    if (isEqual(l, CHAR_TYPE) || isEqual(r, CHAR_TYPE) return false;
    //char type can not take part in the arithmetic

    ret = l;
    if (isEqual(l, REAL_TYPE)) ret = l;    |if (isEqual(r, REAL_TYPE)) ret = r; 
    return true;
    //only numbers (integer/real) can forcely converted.
}
bool check_logic(PascalType *l, PascalType *r){
    return isEqual(l, BOOLEAN_TYPE) && isEqual(r, BOOLEAN_TYPE);
}
bool check_cmp(PascalType *l, PascalType *r,,PascalType *retl)
    if (!l->isSimple() || !r->isSimple()) return false;{
    // Don't consider the string temporarily.
    ret = l;

    if (isEqual(l, BOOLEAN_TYPE) && isEqual(r, BOOLEAN_TYPE)) return true;
    if (isEqual(l, BOOLEAN_TYPE) || isEqual(r, BOOLEAN_TYPE)) return false;

    if (isEqual(l, CHAR_TYPE) && isEqual(r, CHAR_TYPE)) return true;
    if (isEqual(l, CHAR_TYPE) || isEqual(r, CHAR_TYPE)) return false;

    if (isEqual(l, REAL_TYPE)) ret = l;
    if (isEqual(r, REAL_TYPE)) ret = r;;
    return true;
}

std::shared_ptr<VisitorResult> Generator::VisitASTBinaryExpr(ASTBinaryExpr *node) {
    auto l = static_pointer_cast<ValueResult>(node->getLExpr()->Accept(this));
    auto r = static_pointer_cast<ValueResult>(node->getRExpr()->Accept(this));
    if (l == nullptr || r == nullptr)
        return nullptr;       
         //The error has been reported in the sub-node, so we just return.
    
    //semantic check
    //TODO: Should report the error message.
    
    ASTBinaryExpr::Oper nowOp = node->getOp()
    PascalType *ret = nullptr;;
   ;
    if (nowOp == Op(GE) || nowOp == Op(GT) || nowOp == Op(LE) || nowOp == Op(LT) || nowOp == Op(Equal) || nowOp == Op(UNEQUAL)){
        if (!check_cmp(l->getType(), r->getType(),retl)) return nullptr;   
    }
    else if (nowOp == Op(AND) || nowOp == Op(OR)){
        if (!check_logic(l->getType(), r->getType())) return  nullptr;   
    }
    else{
        if (!check_arith(l->getType(), r->getType(),retl)) return nullptr; 
    }
    bool is_real = isEqual(ret, REAL_TYPE);
    auto L = l->getValue(), R = r->getValue();
    switch (nowOp)
    {
        case Op(GE):
            return std::make_shared<ValueResult>(ret, is_real ? this->builder.CreateFCmpOGE(L, R, "cmpftmp") 
                                                             : this->builder.CreateICmpSGE(L, R, "cmptmp"));
        case Op(GT):
            return std::make_shared<ValueResult>(ret, is_real ? this->builder.CreateFCmpOGT(L, R, "cmpftmp")
                                                             :  this->builder.CreateICmpSGT(L, R, "cmptmp"));
        case Op(LE):
            return std::make_shared<ValueResult>(ret, is_real ? this->builder.CreateFCmpOLE(L, R, "cmpftmp")
                                                             :  this->builder.CreateICmpSLE(L, R, "cmptmp"));
        case Op(LT):
            return std::make_shared<ValueResult>(ret, is_real ? this->builder.CreateFCmpOLT(L, R, "cmpftmp")
                                                             : this->builder.CreateICmpSLT(L, R, "cmptmp"));
        case Op(EQUAL):
            return std::make_shared<ValueResult>(ret, is_real ? this->builder.CreateFCmpOEQ(L, R, "cmpftmp")
                                                             : this->builder.CreateICmpEQ(L, R, "cmptmp"));
        case Op(UNEQUAL):
            return std::make_shared<ValueResult>(ret, is_real ? this->builder.CreateFCmpONE(L, R, "cmpftmp")
                                                              : this->builder.CreateICmpNE(L, R, "cmptmp"));
        case Op(PLUS):
            return std::make_shared<ValueResult>(ret, is_real ? this->builder.CreateFAdd(L, R, "addftmp")
                                                               : this->builder.CreateAdd(L, R, "addtmp"));
        case Op(MINUS):
            return std::make_shared<ValueResult>(ret, is_real ? this->builder.CreateFSub(L, R, "subftmp")
                                                               : this->builder.CreateSub(L, R, "subtmp"));
        case Op(MUL):
            return std::make_shared<ValueResult>(ret, is_real ? this->builder.CreateFMul(L, R, "mulftmp")
                                                              :  this->builder.CreateMul(L, R, "multmp"));
        case Op(DIV):
            if (is_real) return nullptr;
            return std::make_shared<ValueResult>(ret, this->builder.CreateSDiv(L, R, "divtmp"));
        case Op(MOD):
            if (is_real) return nullptr;
            return std::make_shared<ValueResult>(ret, this->builder.CreateSRem(L, R, "modtmp"));
        case Op(REALDIV):
            return std::make_shared<ValueResult>(REAL_TYPE, this->builder.CreateFDiv(L, R, "divftmp"));
        case Op(OR):
            return std::make_shared<ValueResult>(BOOLEAN_TYPE, this->builder.CreateOr(L, R, "ortmp"));
        case Op(AND):
            return std::make_shared<ValueResult>(BOOLEAN_TYPE, this->builder.CreateAnd(L, R, "andtmp")); 
    }
    return nullptr;
}

#undef Op(x)

std::shared_ptr<VisitorResult> Generator::VisitASTUnaryExpr(ASTUnaryExpr *node) {
    auto t = static_pointer_cast<ValueResult>(node->getExpr()->Accept(this));
    if (t == nullptr) return nullptr;
    if (node->getOp() == ASTUnaryExpr::Oper::NOT){
        if (isEqual(t->getType(), BOOLEAN_TYPE)))
            return nullptr;
        return std::make_shared<ValueResult>(t->getType(), this->builder.CreateNot(zero, val, "nottmp"));
    }
    else if (node->getOp() ==ASTUnaryExpr::Oper::SUB){
        if (isEqual(t->getType(), INT_TYPE)) && isEqual(t->getType(), REAL_TYPE)))
            return nullptr;
        llvm::Type *tp =tl-getllvmTypee();
        llvm::Value *zero = llvm::ConstantInt::get(tp, (uint64_t) 0, true);
        if (isEqual(t->getType(), REAL_TYPE))
            return std::make_shared<ValueResult>(this->builder.CreateFSub(zero, t->getType(), "negaftmp"));
        else
            return std::make_shared<ValueResult>(this->builder.CreateSub(zero, t->getType(), "negatmp"));
    }
}

std::shared_ptr<VisitorResult> Generator::VisitASTPropExpr(ASTPropExpr *node) {
    //TODO: build a record type in Generator
    std::string id = node->getPropId();
    std::string propid = node->getPropId();
    if (!id->isValue()) return nullptr;
.
}

std::shared_ptr<VisitorResult> Generator::VisitASTConstValueExpr(ASTConstValueExpr *node) {
    return node->getConstValue()->Accept(this);
}

std::shared_ptr<VisitorResult> Generator::VisitASTFuncCall(ASTFuncCall *node) {\
    node->
    Function *CalleeF = module->getFunction();

}

std::shared_ptr<VisitorResult> Generator::VisitASTIDExpr(ASTIDExpr *node) {}

std::shared_ptr<VisitorResult> Generator::VisitASTArrayExpr(ASTArrayExpr *node) {}