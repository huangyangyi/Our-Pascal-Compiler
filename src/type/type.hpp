#ifndef OPC_TYPE_H
#define OPC_TYPE_H

#include <vector>
#include <map>
#include <llvm/IR/Type.h>
#include "../generator/generator.h"
#include <stdint.h>

namespace OurType {
class PascalType {
public:
    enum class TypeGroup { BUILT_IN, ENUM, SUBRANGE, ARRAY, STR, RECORD };
    TypeGroup tg;
    PascalType(TypeGroup tg):tg(tg){}
    bool isSimple(){return tg == TypeGroup::BUILT_IN;}
    bool isIntegerTy() const;
    bool isCharTy() const;
    bool isFloatingPointTy() const;
    bool isBuiltInTy() const;
    bool isStringTy() const;
    bool isSubRangeTy() const;
    bool isRecordTy() const;
    bool isArrayTy() const;
};

class BuiltinType : public PascalType {
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
PascalType* const INT_TYPE = (PascalType *)(&INT_TYPE_INST);
PascalType* const REAL_TYPE = (PascalType *)(&REAL_TYPE_INST);
PascalType* const CHAR_TYPE = (PascalType *)(&CHAR_TYPE_INST);
PascalType* const BOOLEAN_TYPE = (PascalType *)(&BOOLEAN_TYPE_INST);
PascalType* const VOID_TYPE = (PascalType *)(&VOID_TYPE_INST);

bool PascalType::isIntegerTy() const {return isEqual(this, INT_TYPE);}
bool PascalType::isFloatingPointTy() const {return isEqual(this, REAL_TYPE);}
bool PascalType::isCharTy() const {return isEqual(this, CHAR_TYPE);}
bool PascalType::isStringTy() const {return this->tg == TypeGroup::STR;};
bool PascalType::isSubRangeTy() const {return this->tg == TypeGroup::SUBRANGE;};
bool PascalType::isRecordTy() const {return this->tg == TypeGroup::RECORD;};
bool PascalType::isArrayTy() const {return this->tg == TypeGroup::ARRAY;};

class SubRangeType : public PascalType {
public:
//    std::string type_name;
    int low;
    int high;
    SubRangeType(int low, int high): low(low), high(high), PascalType(PascalType::TypeGroup::SUBRANGE) {}
};


class ArrayType : public PascalType {
public:
    std::pair<int, int> range; // pair(low, high)
    PascalType* element_type;
    llvm::ConstantInt* getLLVMLow(llvm::LLVMContext &context) {
        return llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), range.first, true);
    }

    llvm::ConstantInt* getLLVMHigh(llvm::LLVMContext &context) {
        return llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), range.second, true);
    }

    ArrayType(std::pair<int, int> range, PascalType *type): 
        range(range), element_type(type), PascalType(PascalType::TypeGroup::ARRAY) {}
};

class StrType : public PascalType {
public:
    int dim;
    StrType(int dim): dim(dim), PascalType(PascalType::TypeGroup::STR) {}
};

class RecordType : public PascalType {
public:
    int size;
    std::vector<std::string> name_vec;
    std::vector<PascalType *> type_vec;
    RecordType(std::vector<std::string> name_vec, std::vector<PascalType *> type_vec):
        name_vec(name_vec), type_vec(type_vec), PascalType(PascalType::TypeGroup::RECORD) {
        this->size = name_vec.size();
    }
};

class EnumType : public PascalType {
public:
    std::vector<std::string> names_;
    EnumType(std::vector<std::string> names, Generator *g): 
        names_(names), PascalType(PascalType::TypeGroup::ENUM) {
        for (int i = 0; i < names.size(); i++) {
            if (g->named_constants.find(names[i]) != g->named_constants.end()) {
                // multiple constant
                continue;
            } else {
                g->named_constants[names[i]] = llvm::ConstantInt::get(
                    llvm::Type::getInt32Ty(g->context), i, true);
            }
        }
    }
};

bool isEqual(const PascalType *a, const PascalType *b){
    if (a->tg != b->tg) return false;
    if (a->tg == PascalType::TypeGroup::BUILT_IN)
        return ((BuiltinType *)a)->type == ((BuiltinType *)b)->type;
}


llvm::Type *getLLVMType(llvm::LLVMContext &context, const PascalType *p_type) {
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

        StrType *str = (StrType *)p_type;
        return llvm::ArrayType::get(getLLVMType(context, CHAR_TYPE), (uint64_t)(str->dim));

    } else if (p_type->tg == PascalType::TypeGroup::ARRAY) {

        ArrayType *array = (ArrayType *)p_type;
        llvm::ArrayType *ret = nullptr;
        int len = array->range.second - array->range.first;
        ret = llvm::ArrayType::get(getLLVMType(context, array->element_type), (uint64_t)len);
        return ret;

    } else if (p_type->tg == PascalType::TypeGroup::RECORD) {
        
        RecordType *record = (RecordType *)p_type;
        std::vector<llvm::Type *> llvm_type_vec;
        for (auto t : record->type_vec) {
            llvm_type_vec.push_back(getLLVMType(context, t));
        }
        return llvm::StructType::get(context, llvm_type_vec);

    } else if (p_type->tg == PascalType::TypeGroup::ENUM) {
        
        // does not mean that enum type does not exist
        // it means that we do not consider it as a basic type
        return llvm::Type::getInt32Ty(context);

    } else if (p_type->tg == PascalType::TypeGroup::SUBRANGE) {
        // not implemented
        return nullptr;
    }
}

}; // namespace Type

#endif //OPC_TYPE_H