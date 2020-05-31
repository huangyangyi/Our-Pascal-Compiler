
#include <iostream>
#include "generator.h"
#include "generator_result.hpp"
#include "../ast/ast_type.h"
#include "type/type.h"

std::shared_ptr<VisitorResult> Generator::VisitASTType(ASTType *node) {
    ASTType::TypeName type_name = node->getTypeName();
    if (type_name == ASTType::TypeName::INTEGER)
        return std::make_shared<TypeResult>(OurType::INT_TYPE);
    else if (type_name == ASTType::TypeName::REAL)
        return std::make_shared<TypeResult>(OurType::REAL_TYPE);
    else if (type_name == ASTType::TypeName::BOOLEAN)
        return std::make_shared<TypeResult>(OurType::BOOLEAN_TYPE);
    else if (type_name == ASTType::TypeName::CHAR)
        return std::make_shared<TypeResult>(OurType::CHAR_TYPE);
    else 
        return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTSimpleTypeDecl(ASTSimpleTypeDecl *node) {
    if (node->my_type == ASTSimpleTypeDecl::MyType::BUILTIN_TYPE) {
        auto type_name = node->type_name->Accept(this);
        return type_name;
    } else if (node->my_type == ASTSimpleTypeDecl::MyType::DEFINED_ID) {
        PascalType *ret = nullptr;
        
        // cannot be an variable
        if (this->getCurrentBlock()->named_values.count(node->defined_id) > 0) {
            return nullptr;
        }

        for (int i = this->block_stack.size()-1; i >= 0; i--) {
            CodeBlock *block = this->block_stack[i];
            if (block->named_types.find(node->defined_id) != block->named_types.end()) {
                ret = block->named_types[node->defined_id];
            }
        }
        if (ret == nullptr) return nullptr;
        else return std::make_shared<VisitorResult>(TypeResult(ret));
    } else if (node->my_type == ASTSimpleTypeDecl::MyType::VALUE_RANGE) {
        std::shared_ptr<ValueResult> low_ret = std::static_pointer_cast<ValueResult>(node->low->Accept(this));
        std::shared_ptr<ValueResult> high_ret = std::static_pointer_cast<ValueResult>(node->high->Accept(this));
        
        int low, high;
        if (llvm::ConstantInt *CI = llvm::dyn_cast<llvm::ConstantInt>(low_ret->getValue())) {
            low = CI->getSExtValue();
        } else {
            return nullptr;
        }
        if (llvm::ConstantInt *CI = llvm::dyn_cast<llvm::ConstantInt>(high_ret->getValue())) {
            high = CI->getSExtValue();
        } else {
            return nullptr;
        }

        if (node->neg_low) low *= -1;
        if (node->neg_high) high *= -1;
        
        OurType::PascalType *range = new OurType::SubRangeType(low, high);
        return std::make_shared<TypeResult>(range);

    } else if (node->my_type == ASTSimpleTypeDecl::MyType::ID_RANGE) {
        std::string low_id = node->low_name;
        std::string high_id = node->high_name;

        // grab constant variable
        llvm::Constant *low, *high;
        if (this->named_constants.find(low_id) != this->named_constants.end()) {
            low = this->named_constants[low_id];
        } else {
            return nullptr;
        }
        if (this->named_constants.find(high_id) != this->named_constants.end()) {
            high = this->named_constants[high_id];
        } else {
            return nullptr;
        }

        // grab int from ConstantInt*
        int low_int, high_int;
        if (llvm::ConstantInt *CI = llvm::dyn_cast<llvm::ConstantInt>(low)) {
            low_int = CI->getSExtValue();
        } else {
            return nullptr;
        }
        if (llvm::ConstantInt *CI = llvm::dyn_cast<llvm::ConstantInt>(high)) {
            high_int = CI->getSExtValue();
        } else {
            return nullptr;
        }

        OurType::PascalType *range = new OurType::SubRangeType(low_int, high_int);
        return std::make_shared<TypeResult>(range);

    } else if (node->my_type == ASTSimpleTypeDecl::MyType::ENUM) {
        std::shared_ptr<NameList> list_ret;
        std::vector<std::string> name_list;
        if (list_ret = std::static_pointer_cast<NameList>(node->name_list->Accept(this))) {
            name_list = list_ret->getNameList();
        } else {
            std::cout << node->get_location() << " not a name list." << endl;
        }
        OurType::EnumType *new_enum = new OurType::EnumType(name_list, this);
        return std::make_shared<TypeResult>(new_enum);
    }
}

std::shared_ptr<VisitorResult> Generator::VisitASTArrayTypeDecl(ASTArrayTypeDecl *node) {
    std::shared_ptr<TypeResult> tr;
    int low, high;
    tr = std::static_pointer_cast<TypeResult>(node->getSimpleTypeDecl()->Accept(this));
    if (tr->getType()->tg == OurType::PascalType::TypeGroup::SUBRANGE) {
        OurType::SubRangeType *range = (OurType::SubRangeType *)tr->getType();
        low = range->low;
        high = range->high;
    } else {
        // not a range
        std::cout << node->get_location() << "index_range is not a range" << std::endl;
        return nullptr;
    }
    
    std::shared_ptr< TypeResult > type_ret;
    OurType::PascalType *array_type;
    if (type_ret = std::static_pointer_cast< TypeResult >(node->getTypeDecl()->Accept(this))) {
        array_type = type_ret->getType();
    } else {
        // not a type
        std::cout << node->get_location() << "array_type is not a type" << std::endl;
        return nullptr;
    }

    OurType::ArrayType *this_type = new OurType::ArrayType(
        std::make_pair(low, high),
        array_type
    ); 
    return std::make_shared<TypeResult>(this_type);
}

std::shared_ptr<VisitorResult> Generator::VisitASTFieldDecl(ASTFieldDecl *node) {
    std::shared_ptr<NameList> list_ret;
    std::vector<std::string> name_list;
    if (list_ret = std::static_pointer_cast<NameList>(node->getNameList()->Accept(this))) {
        name_list = list_ret->getNameList();
    } else {
        std::cout << node->get_location() << " not a name list." << endl;
    }

    std::shared_ptr< TypeResult > type_ret;
    OurType::PascalType *type;
    if (type_ret = std::static_pointer_cast< TypeResult >(node->getTypeDecl()->Accept(this))) {
        type = type_ret->getType();
    } else {
        // not a type
        std::cout << node->get_location() << "type_decl does not have a type" << std::endl;
        return nullptr;
    }

    return std::make_shared<TypeDeclResult>(list_ret->getNameList(), type_ret->getType());
}

std::shared_ptr<VisitorResult> Generator::VisitASTFieldDeclList(ASTFieldDeclList *node) {
    std::shared_ptr<VisitorResult> fd_ret;
    std::shared_ptr<TypeDeclListResult> ret(new TypeDeclListResult());
    for (auto fd : node->getFielddeclList()) {
        fd_ret = fd->Accept(this);
        
        std::shared_ptr<TypeDeclResult> tdr;
        if (tdr = static_pointer_cast<TypeDeclResult>(fd_ret)) {
            ret->addTypeDeclResult(tdr);
        } else {
            std::cout << fd->get_location() << "in a record_decl but not a type_decl" << std::endl;
        }
    }
    return ret;
}

std::shared_ptr<VisitorResult> Generator::VisitASTRecordTypeDecl(ASTRecordTypeDecl *node) {
    shared_ptr<TypeDeclListResult> decls = std::static_pointer_cast<TypeDeclListResult>(
        node->getFieldDeclList()->Accept(this));
    if (decls) {
        std::vector<std::string> name_vec;
        std::vector<OurType::PascalType *> type_vec;
        for(auto tdr : decls->getTypeDeclList()) {
            OurType::PascalType *type = tdr->getType();
            for(auto attr_name : tdr->getNameList()) {
                name_vec.push_back(attr_name);
                type_vec.push_back(type);
            }
        }
        OurType::PascalType *record_type = new OurType::RecordType(name_vec, type_vec);
        return std::make_shared<TypeResult>(record_type);
    } else {
        std::cout << node->get_location() << "fail to generate a record type." << std::endl;
        return nullptr;
    }
}

std::shared_ptr<VisitorResult> Generator::VisitASTTypeDefinition(ASTTypeDefinition *node) {
    std::string id = node->getId();
    std::shared_ptr<TypeResult> tr = std::static_pointer_cast<TypeResult>(
        node->getTypeDecl()->Accept(this));
    if (tr) {
        OurType::PascalType *type = tr->getType();
        bool defined = false;
        for (int i = this->block_stack.size()-1; i >= 0; i--) {
            CodeBlock *block = this->block_stack[i];
            if (block->named_types.find(id) != block->named_types.end()) {
                defined = true;
                break;
            }
        }
        if (defined) {
            std::cout << node->get_location() << "multiple type definition." << std::endl;
        } else {
            this->getCurrentBlock()->named_types[id] = type;
        }
    } else {
        std::cout << node->get_location() << "fail to generate a type." << std::endl;
    }
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTTypeDeclList(ASTTypeDeclList *node) {
    for(auto td : node->getTypeList()) {
        td->Accept(this);
    }
    return nullptr;
}

std::shared_ptr<VisitorResult> Generator::VisitASTTypePart(ASTTypePart *node) {
    return node->getTypeDeclList()->Accept(this);
}