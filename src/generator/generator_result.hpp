#ifndef OPC_GENERATOR_RESULT_H
#define OPC_GENERATOR_RESULT_H

#include "../visitor.h"
#include "../type/type.hpp"
#include <vector>
#include <string>

#include <llvm/IR/Value.h>
#include <llvm/IR/Type.h>

using namespace OurType;

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
    ValueResult(OurType::PascalType *type, llvm::Value *value, llvm::Value *mem=nullptr) : type_(type), value_(value), mem_(mem) {}

    ~ValueResult() = default;

    llvm::Value *getValue() const { return this->value_; }
    llvm::Value *getMem() const { return this->mem_; }
    PascalType *getType() const { return this->type_; }
    llvm::Type *getllvmType() const {return this->value_->getType();}
private:
    llvm::Value *value_; //value
    llvm::Value *mem_; //pointer
    PascalType *type_;
};

/*
template<typename T> class PairConstant : public VisitorResult {
    PairConstantInt(T f, T s): first_(f), second_(s) {}
    T first() { return this->first_; }
    T second() { return this->second_; }
private:
    T first_, second_; // for array, first=low, second=high
}

class PairResult : public VisitorResult {
public:
    PairResult(std::shared_ptr<ValueResult> f, std::shared_ptr<ValueResult> s): first_(f), second_(s) {}
    std::shared_ptr<ValueResult> first() { return this->first_; }
    std::shared_ptr<ValueResult> second() { return this->second_; }

private:
    std::shared_ptr<ValueResult> first_, second_;
};
*/

class ValueListResult : public VisitorResult {
public:
    ValueListResult(std::vector<std::shared_ptr<ValueResult> > value_list) : value_list_(value_list){}

    ~ValueListResult() = default;

    std::vector<std::shared_ptr<ValueResult> > &getValueList() const { return this->value_list_; }
private:
    std::vector<std::shared_ptr<ValueResult> > value_list_;
};

class NameListResult : public VisitorResult {
public:
    NameListResult(ASTNameList *ast_name_list, bool is_var = false) : ast_name_list_(ast_name_list), is_var_(is_var){}

    ~NameListResult() = default;

    ASTNameList *getNameList() const { return this->ast_name_list_; }
    bool is_var(){return is_var_;}
private:
    ASTNameList *ast_name_list_;
    bool is_var_;
};

class TypeResult : public VisitorResult {
public:
    TypeResult(OurType::PascalType *type, bool is_var = false) :type_(type), is_var_(is_var){}
    OurType::PascalType *getType() const {return type_;}
    bool is_var(){return is_var_;}
private:
    OurType::PascalType *type_;
    bool is_var_; //use when it is served for function parameters.
};

class TypeListResult : public VisitorResult {
public:
    TypeListResult(std::vector<std::shared_ptr<TypeResult> > type_list, std::vector<std::string> name_list) 
        :type_list_(type_list), name_list_(name_list){}
    std::vector<std::shared_ptr<TypeResult> > getTypeList() {return type_list_;}
    std::vector<std::string> getNameList(){return name_list_;}
private:
    std::vector<std::shared_ptr<TypeResult> >type_list_;
    std::vector<std::string> name_list_;
};

class TypeDeclResult : public VisitorResult {
public:    
    TypeDeclResult(ASTNameList *nl, OurType::PascalType *type):
        ast_name_list(nl), type_(type) {}
    ASTNameList *getNameList(void) { return this->ast_name_list; }
    const OurType::PascalType const *getType(void) { return this->type_; }

private:
    ASTNameList *ast_name_list;
    const OurType::PascalType const *type_;
};

class TypeDeclListResult : public VisitorResult {
public:
    TypeDeclListResult() {}
    void addTypeDeclResult(std::shared_ptr<TypeDeclResult> tdr) {
        this->type_decl_list_.push_back(tdl);
    }
    std::vector<std::shared_ptr<TypeDeclResult> > getTypeDeclList() {
        return this->type_decl_list_;
    }
private:
    std::vector<std::shared_ptr<TypeDeclResult> > type_decl_list_;
}
#endif // OPC_GENERATOR_RESULT_H