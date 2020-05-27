#ifndef OPC_TYPE_H
#define OPC_TYPE_H

#include <vector>
#include <map>
#include <llvm/IR/Type.h>

namespace PascalType {
class PascalType {
public:
    enum class TypeGroup { BUILT_IN, ENUM, SUBRANGE, ARRAY, STR, RECORD };
    TypeGroup tg;
    PascalType(TypeGroup tg):tg(tg){}
    bool isSimple(){return tg == TypeGroup::BUILT_IN;}
};

class BuiltinType : PascalType {
public:
    enum class BasicTypes { INT, REAL, CHAR, BOOLEAN, VOID };
    BasicTypes type;
    BuiltinType(BasicTypes type): type(type), PascalType(PascalType::TypeGroup::BUILT_IN) {};    
};

const BuiltinType INT_TYPE_INST(BuiltinType::BasicTypes::INT);
const BuiltinType REAL_TYPE_INST(BuiltinType::BasicTypes::REAL);
const BuiltinType CHAR_TYPE_INST(BuiltinType::BasicTypes::CHAR);
const BuiltinType BOOLEAN_TYPE_INST(BuiltinType::BasicTypes::BOOLEAN);
const BuiltinType VOID_TYPE_INST(BuiltinType::BasicTypes::VOID);
const PascalType* INT_TYPE = std::static_pointer_cast<PascalType>(&INT_TYPE_INST);
const PascalType* REAL_TYPE = std::static_pointer_cast<PascalType>(&REAL_TYPE_INST);
const PascalType* CHAR_TYPE = std::static_pointer_cast<PascalType>(&CHAR_TYPE_INST);
const PascalType* BOOLEAN_TYPE = std::static_pointer_cast<PascalType>(&BOOLEAN_TYPE_INST);
const PascalType* VOID_TYPE = std::static_pointer_cast<PascalType>(&VOID_TYPE_INST);



class EnumType : PascalType {
public:
    std::string type_name;
    std::vector<std::string> enum_names;
    EnumType(const std::string &type_name, const std::vector<std::string> &enum_names): type_name(type_name), enum_names(enum_names),PascalType(PascalType::TypeGroup::ENUM) {}
};

class SubRangeType : PascalType {
public:
    std::string type_name;
    int low;
    int high;
    SubRangeType(const std::string &type_name, int low, int high): type_name(type_name), low(low), high(high), PascalType(PascalType::TypeGroup::SUBRANGE) {}
};

class ArrayType : PascalType {
public:
    int dim;
    PascalType* type;
    ArrayType(int dim, PascalType *): dim(dim), type(type), PascalType(PascalType::TypeGroup::ARRAY) {}
};

class StrType : PascalType {
public:
    int dim;
    StrType(int dim): dim(dim), PascalType(PascalType::TypeGroup::STR) {}
};

bool isEqual(PascalType *a, PascalType *b){
    if (a->tg != b->tg) return false;
    if (a->tg == PascalType::TypeGroup::BUILT_IN)
        return ((BuiltinType *)a)->type == ((BuiltinType *)b)->type;
    
}

llvm::Type* getLLVMType(llvm::LLVMContext context, PascalType *p_type) {
    if (p_type->tg == PascalType::TypeGroup::BUILT_IN) {
        if (isEqual(p_type, INT_TYPE))
            return llvm::Type::getInt32Ty(context);
        else if (isEqual(p_type, REAL_TYPE))
            return llvm::Type::getFloatTy(context);
        else if (isEqual(p_type, CHAR_TYPE))
            return llvm::Type::getInt8Ty(context);
        else if (isEqual(p_type, BOOLEAN_TYPE))
            return llvm::Type::getInt1Ty(context);
        else if (isEqual(p_type, VOID_TYPE))
            return llvm::Type::getVoidTy(context);
        else
            return nullptr;
    } else if (p_type->tg == PascalType::TypeGroup::STR) {

    } else if (p_type->tg == PascalType::TypeGroup::ARRAY) {
        
    } else if (p_type->tg == PascalType::TypeGroup::RECORD) {

    } else if (p_type->tg == PascalType::TypeGroup::ENUM) {

    } else if (p_type->tg == PascalType::TypeGroup::SUBRANGE) {
    
    }
}

}; // namespace PascalType

#endif //OPC_TYPE_H