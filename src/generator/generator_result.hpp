#ifndef OPC_GENERATOR_RESULT_H
#define OPC_GENERATOR_RESULT_H

#include "../visitor.h"
#include <vector>
#include <string>
#include <llvm/IR/Values.h>

class NameList : VisitorResult {
public:
    NameList(const std::vector<std::string> &list) : list_(list) {};

    ~NameList() = default;

    const std::vector<std::string> &get_list() const { return this->list_; };
private:
    std::vector<std::string> list_;
}

class ValueResult : VisitorResult {
public:
    ValueResult(llvm::Value *value, llvm::Value *mem = nullptr) : value_(value), mem(mem) {}

    ~ValueResult() = default;

    llvm::Value *get_value() const { return this->value_; }

private:
    llvm::Value *value_;
    llvm::Value *mem_
}

#endif // OPC_GENERATOR_RESULT_H