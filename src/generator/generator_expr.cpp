#include "generator.h"
#include "generator_result.hpp"
#include "../ast/ast_expr.h"
#include <llvm/IR/Value.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <iostream>
#include <stdint.h>
#include <llvm/Support/Casting.h>

using namespace OurType;

std::shared_ptr<VisitorResult> Generator::VisitASTExpressionList(ASTExpressionList *node) {
    auto expr_list = node->getExprList();
    std::vector<std::shared_ptr<ValueResult>> ret;
    int cnt = 0;
    for (auto expr_node: expr_list){
        auto val = static_pointer_cast<ValueResult>(expr_node->Accept(this));
        if (val == nullptr) {
            std::cerr << "meet nullptr at VisitASTExpressionList! at parameter: " << cnt << std::endl;
            return nullptr;
        }
        ret.push_back(val);
        cnt++;
    }
    return std::make_shared<ValueListResult>(ret);
}

#define Op(x) ASTBinaryExpr::Oper::x

bool check_arith(PascalType *l, PascalType *r, PascalType *&ret){
    if (!l->isSimple() || !r->isSimple()) return false;
    // Don't consider the string temporarily.
    if (isEqual(l, BOOLEAN_TYPE) || isEqual(r, BOOLEAN_TYPE)) return false;
    //boolean type can not take part in the arithmetic
    if (isEqual(l, CHAR_TYPE) || isEqual(r, CHAR_TYPE)) return false;
    //char type can not take part in the arithmetic

    ret = l;
    if (isEqual(l, REAL_TYPE)) ret = l;    
    if (isEqual(r, REAL_TYPE)) ret = r; 
    return true;
    //only numbers (integer/real) can forcely converted.
}
bool check_logic(PascalType *l, PascalType *r){
    return isEqual(l, BOOLEAN_TYPE) && isEqual(r, BOOLEAN_TYPE);
}
bool check_cmp(PascalType *l, PascalType *r, PascalType *&ret) {
    if (!l->isSimple() || !r->isSimple()) return false;
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
    auto l = std::static_pointer_cast<ValueResult>(node->getLExpr()->Accept(this));
    auto r = std::static_pointer_cast<ValueResult>(node->getRExpr()->Accept(this));
    if (l == nullptr || r == nullptr)
        return nullptr;
        //The error has been reported in the sub-node, so we just return.
    
    //semantic check
    ASTBinaryExpr::Oper nowOp = node->getOp();
    PascalType *ret = nullptr;
    if (nowOp == Op(GE) || nowOp == Op(GT) || nowOp == Op(LE) || nowOp == Op(LT) || nowOp == Op(EQUAL) || nowOp == Op(UNEQUAL)){
        if (!check_cmp(l->getType(), r->getType(), ret)) 
            return RecordErrorMessage("The type of two side in binary compare expression does not matched.", node->get_location_pairs());
    }
    
    else if (nowOp == Op(AND) || nowOp == Op(OR)){
        std::cout << isEqual(l->getType(), BOOLEAN_TYPE) << std::endl;
        std::cout << isEqual(r->getType(), BOOLEAN_TYPE) << std::endl;
        if (!check_logic(l->getType(), r->getType()))
            return RecordErrorMessage("Both sides of the binary logic expression need to be BOOLEAN type.", node->get_location_pairs());
    }
    else{
        if (!check_arith(l->getType(), r->getType(),ret))
            return RecordErrorMessage("The type of two side in binary arithmetic expression does not matched.", node->get_location_pairs());
    }
    bool is_real = isEqual(ret, REAL_TYPE);
    if (nowOp == ASTBinaryExpr::Oper::REALDIV)
        is_real = true;
    auto L = l->getValue(), R = r->getValue();
    if (is_real){
        L = this->builder.CreateUIToFP(L, getLLVMType(this->context, REAL_TYPE));
        R = this->builder.CreateUIToFP(R, getLLVMType(this->context, REAL_TYPE));
    }
    switch (nowOp)
    {
        case Op(GE):
            return std::make_shared<ValueResult>(BOOLEAN_TYPE, is_real ? this->builder.CreateFCmpOGE(L, R, "cmpftmp") 
                                                                       : this->builder.CreateICmpSGE(L, R, "cmptmp"));
        case Op(GT):
            return std::make_shared<ValueResult>(BOOLEAN_TYPE, is_real ? this->builder.CreateFCmpOGT(L, R, "cmpftmp")
                                                                      :  this->builder.CreateICmpSGT(L, R, "cmptmp"));
        case Op(LE):
            return std::make_shared<ValueResult>(BOOLEAN_TYPE, is_real ? this->builder.CreateFCmpOLE(L, R, "cmpftmp")
                                                                      :  this->builder.CreateICmpSLE(L, R, "cmptmp"));
        case Op(LT):
            return std::make_shared<ValueResult>(BOOLEAN_TYPE, is_real ? this->builder.CreateFCmpOLT(L, R, "cmpftmp")
                                                                        : this->builder.CreateICmpSLT(L, R, "cmptmp"));
        case Op(EQUAL):
            return std::make_shared<ValueResult>(BOOLEAN_TYPE, is_real ? this->builder.CreateFCmpOEQ(L, R, "cmpftmp")
                                                                       : this->builder.CreateICmpEQ(L, R, "cmptmp"));
        case Op(UNEQUAL):
            return std::make_shared<ValueResult>(BOOLEAN_TYPE, is_real ? this->builder.CreateFCmpONE(L, R, "cmpftmp")
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
            if (is_real) return RecordErrorMessage("The type of two side in div must be INTEGER.", node->get_location_pairs());
            return std::make_shared<ValueResult>(ret, this->builder.CreateSDiv(L, R, "divtmp"));
        case Op(MOD):
            if (is_real) return RecordErrorMessage("The type of two side in mod must be INTEGER.", node->get_location_pairs());
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

#undef Op

std::shared_ptr<VisitorResult> Generator::VisitASTUnaryExpr(ASTUnaryExpr *node) {
    auto t = std::static_pointer_cast<ValueResult>(node->getExpr()->Accept(this));
    if (t == nullptr) return nullptr;
    if (node->getOp() == ASTUnaryExpr::Oper::NOT){
        if (!isEqual(t->getType(), BOOLEAN_TYPE))
            return RecordErrorMessage("The type after not must be BOOLEAN.", node->get_location_pairs());
        return std::make_shared<ValueResult>(t->getType(), this->builder.CreateNot(t->getValue(), "nottmp"));
    }
    else if (node->getOp() ==ASTUnaryExpr::Oper::SUB){
        if (isEqual(t->getType(), INT_TYPE) && isEqual(t->getType(), REAL_TYPE))
            return RecordErrorMessage("The type after negative sign must be INTEGER or REAL.", node->get_location_pairs());
        llvm::Type *tp =t->getllvmType();
        llvm::Value *zero = llvm::ConstantInt::get(tp, (uint64_t) 0, true);
        if (isEqual(t->getType(), REAL_TYPE))
            return std::make_shared<ValueResult>(t->getType(), this->builder.CreateFSub(zero, t->getValue(), "negaftmp"));
        else
            return std::make_shared<ValueResult>(t->getType(), this->builder.CreateSub(zero, t->getValue(), "negatmp"));
    }
}

std::shared_ptr<VisitorResult> Generator::VisitASTPropExpr(ASTPropExpr *node) {
    std::string id = node->getId();
    std::string propid = node->getPropId();
    auto val = std::static_pointer_cast<ValueResult>((new ASTIDExpr(id))->Accept(this));
    auto record_type_ = val->getType();
    if (!record_type_->isRecordTy())
        return RecordErrorMessage("Non-record type can not use '.'.", node->get_location_pairs());
    auto record_type = (RecordType *)record_type_;
    auto name_vec = record_type->name_vec;
    auto type_vec = record_type->type_vec;
    int bias = -1;
    for (int i = 0; i < name_vec.size(); i++)
        if (name_vec[i] == propid){
            bias = i;
            break;
        }
    if (bias == -1)
        return RecordErrorMessage(id + " do not have property " + propid, node->get_location_pairs());
    
    std::vector<llvm::Value *> gep_vec = {llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 0, true),
                                          llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), bias, true)};
    
    llvm::Value *mem = builder.CreateGEP(val->getMem(), gep_vec, "record_field");
    llvm::Value *ret = this->builder.CreateLoad(mem);
    return std::make_shared<ValueResult>(type_vec[bias], ret, mem);
}

std::shared_ptr<VisitorResult> Generator::VisitASTConstValueExpr(ASTConstValueExpr *node) {
    return node->getConstValue()->Accept(this);
}

std::shared_ptr<VisitorResult> Generator::VisitASTFuncCall(ASTFuncCall *node) {
    ASTExpressionList *argList = node->getArgList();
    std::shared_ptr<ValueListResult> value_list;
    std::vector<std::shared_ptr<ValueResult>> value_vector;
    bool have_args = true;
    if (argList == nullptr) {
        have_args = false;
    } else {
        value_list = std::static_pointer_cast<ValueListResult>(node->getArgList()->Accept(this));
        value_vector = value_list ->getValueList();
        have_args = true;
    }
    for (int i = block_stack.size() - 1; i >= 0; i--){
        std::string func_name = node->getFuncId();
        FuncSign *funcsign = block_stack[i]->find_funcsign(func_name);
        if (funcsign == nullptr ) continue;
        //Note the function/procedure can not be overridden in pascal, so the function is matched iff the name is matched.
        // VERY IMPORTANT !!!
        // NameList().size include all local variables that require to be passed
        // we should compare NameList.size() - n_local
        // which is the actual arg size
        if (funcsign->getNameList().size() - funcsign->getLocalVariablesNum() != value_vector.size())
            RecordErrorMessage("Can't find function " + func_name + ": you have " + std::to_string(value_vector.size()) + "parameters, but the defined one has " 
              + std::to_string(funcsign->getNameList().size() - funcsign->getLocalVariablesNum()) + "parameters.", node->get_location_pairs());
        
        auto name_list = funcsign->getNameList();
        auto type_list = funcsign->getTypeList();
        auto var_list = funcsign->getVarList();
        auto return_type = funcsign->getReturnType();
        llvm::Function *callee = block_stack[i]->find_function(func_name);
        std::vector<llvm::Value*> parameters;

        // adding local variables
        // in generator_program.cpp, we define all locals at the head of the para list
        int cur;
        int n_local = funcsign->getLocalVariablesNum();
        for(cur = 0; cur < n_local; cur++) {
            std::string local_name = name_list[cur];
            if (this->getCurrentBlock()->named_values.find(local_name) == this->getCurrentBlock()->named_values.end()) {
                std::cout << node->get_location() << "local variable " << local_name << " need to be passed, but not found." << std::endl;
                parameters.push_back(nullptr);
            } else {
                parameters.push_back(this->getCurrentBlock()->named_values[local_name]);
            }
        }

        // PASSING function args
        for (auto value: value_vector){
            if (!isEqual(value->getType(), type_list[cur])) {
                std::cerr << node->get_location() << "type does not match on function calling. " << std::endl;
                return nullptr; //Error
            }
            if (value->getMem() != nullptr) {
                parameters.push_back(value->getMem());
            } else {
                this->temp_variable_count++;

                // here we encounter a literally const value as a parameter
                // we add a local variable to the IRBuilder
                // but do not reflect it in Current_CodeBlock->named_values
                // thus we do not add abnormal local variables when we declare another function/procedure
                llvm::AllocaInst *mem = this->builder.CreateAlloca(
                    getLLVMType(this->context, type_list[cur]), 
                    nullptr, 
                    "0_" + std::to_string(this->temp_variable_count)
                );
                this->builder.CreateStore(value->getValue(), mem);
                parameters.push_back(mem);
            }
            cur++;
        } 
        return std::make_shared<ValueResult>(funcsign->getReturnType(), builder.CreateCall(callee, parameters));//, "call_"+ node->getFuncId()
    }
    // Currently, sys_function will use no local variables that has cascade relation
    // So we do not need to deal with the locals and do it simply
    if (isSysFunc(node->getFuncId())) {
        return std::make_shared<ValueResult>(OurType::VOID_TYPE, genSysFunc(node->getFuncId(), value_vector));
    }
    std::cout << node->getFuncId() << std::endl;
    std::cout << node->get_location() << "function not found." << std::endl;
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTIDExpr(ASTIDExpr *node) {
    std::string name = node->getId();
    //std::cout << "ID : " << name << std::endl;
    if (this->getCurrentBlock()->isValue(name)){
        llvm::Value *mem = this->getCurrentBlock()->named_values[name];
        llvm::Value *value = this->builder.CreateLoad(mem);
        std::cerr << "Get local named value: " << name << std::endl;
        return std::make_shared<ValueResult>(this->getVarType(name), value, mem);
    } else if (this->block_stack[0]->isValue(name)){
        llvm::Value *mem = this->block_stack[0]->named_values[name];
        llvm::Value *value = this->builder.CreateLoad(mem);
        std::cerr << "Get global named value: " << name << std::endl;
        return std::make_shared<ValueResult>(this->block_stack[0]->named_types[name], value, mem);
    } else {
        std::cout << "start calling no arg func : " << name << std::endl;
        ASTFuncCall *func_call = new ASTFuncCall(name, nullptr);
        auto ret = func_call->Accept(this);
        std::cout << "finish calling no arg func : " << name << " , return " << (ret == nullptr ? "is" : "is not") << " nullptr" << std::endl;
        if (ret == nullptr) {
            std::cerr << node->get_location() << name << " is neither a variable nor a no-arg function. Cannot get named value: " << name << std::endl;
            return nullptr;
        } else {
            return ret;
        }
    }
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTArrayExpr(ASTArrayExpr *node) {
    auto index = std::static_pointer_cast<ValueResult>(node->getExpr()->Accept(this));
    auto array = std::static_pointer_cast<ValueResult>((new ASTIDExpr(node->getId()))->Accept(this));
    ArrayType* array_type = (ArrayType*)(array->getType());
    if (!isEqual(index->getType(), array_type->element_type)) return nullptr;

    auto offset = this->builder.CreateSub(index->getValue(), array_type->getLLVMLow(this->context), "subtmp");
    std::vector<llvm::Value*> offset_vec;
    offset_vec.push_back(llvm::ConstantInt::get(llvm::Type::getInt32Ty(this->context), 0));
    offset_vec.push_back(offset);
    llvm::Value *mem = builder.CreateGEP( array->getMem(), offset_vec, "ArrayCall");
    llvm::Value *value = this->builder.CreateLoad(mem);
    return std::make_shared<ValueResult>(array_type->element_type, value, mem);
}
