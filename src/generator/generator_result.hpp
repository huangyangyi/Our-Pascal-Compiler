#ifndef OPC_GENERATOR_RESULT_H
#define OPC_GENERATOR_RESULT_H

#include "../visitor.h"
#include "../type/type.hpp"
#include <vector>
#include <string>

#include <llvm/IR/Value.h>
#include <llvm/IR/Type.h>

class NameList : public VisitorResult {
public:
    NameList(const std::vector<std::string> &list) : list_(list) {};

    ~NameList() = default;

    const std::vector<std::string> &get_list() const { return this->list_; };
private:
    std::vector<std::string> list_;
};

class ValueResult : public VisitorResult {
public:
    ValueResult(PascalType *type, llvm::Value *value, llvm::Value *mem=nullptr) : type_(type), value_(value), mem_(mem) {}

    ~ValueResult() = default;

    llvm::Value *getValue() const { return this->value_; }
    llvm::Value *getMem() const { return this->mem_; }
    PascalType::PascalType *getType() const { return this->type_; }
    llvm::Type::TypeID getllvmType() const {return this->value_->getType()->getTypeID();}
private:
    llvm::Value *value_; //value
    llvm::Value *mem_; //pointer
    PascalType::PascalType *type_;
};

class ValueListResult : public VisitorResult {
public:
    ValueResult(std::vector<llvm::Value *>value_list) : value_list_(value_list){}

    ~ValueResult() = default;

    std::vector<llvm::Value *> getValueList() const { return this->value_list_; }
private:
    std::vector<llvm::Value *>value_list_;
};

class TypeResult : public VisitorResult {
public:
    TypeResult(PascalType * type)
    PascalType::PascalType *getType() const {return type_;}
private:
    PascalType::PascalType * type_;
}

#endif // OPC_GENERATOR_RESULT_H