#include "type.h"
namespace OurType {

    const BuiltinType INT_TYPE_INST(BuiltinType::BasicTypes::INT);
    const BuiltinType REAL_TYPE_INST(BuiltinType::BasicTypes::REAL);
    const BuiltinType CHAR_TYPE_INST(BuiltinType::BasicTypes::CHAR);
    const BuiltinType BOOLEAN_TYPE_INST(BuiltinType::BasicTypes::BOOLEAN);
    const BuiltinType VOID_TYPE_INST(BuiltinType::BasicTypes::VOID);
    PascalType *const INT_TYPE = (PascalType *) (&INT_TYPE_INST);
    PascalType *const REAL_TYPE = (PascalType *) (&REAL_TYPE_INST);
    PascalType *const CHAR_TYPE = (PascalType *) (&CHAR_TYPE_INST);
    PascalType *const BOOLEAN_TYPE = (PascalType *) (&BOOLEAN_TYPE_INST);
    PascalType *const VOID_TYPE = (PascalType *) (&VOID_TYPE_INST);
    bool PascalType::isSimple() const { return tg == TypeGroup::BUILT_IN; }

    bool PascalType::isIntegerTy() const { return isEqual(this, INT_TYPE); }

    bool PascalType::isFloatingPointTy() const { return isEqual(this, REAL_TYPE); }

    bool PascalType::isCharTy() const { return isEqual(this, CHAR_TYPE); }

    bool PascalType::isStringTy() const { return this->tg == TypeGroup::STR; };

    bool PascalType::isBuiltInTy() const {
        return this->tg == TypeGroup::BUILT_IN;
    }

    bool PascalType::isSubRangeTy() const { return this->tg == TypeGroup::SUBRANGE; };

    bool PascalType::isRecordTy() const { return this->tg == TypeGroup::RECORD; };

    bool PascalType::isArrayTy() const { return this->tg == TypeGroup::ARRAY; }

    PascalType::PascalType(PascalType::TypeGroup tg) : tg(tg) {};

    EnumType::EnumType(std::vector<std::string> names, Generator *g) :
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

    SubRangeType::SubRangeType(int low, int high) : low(low), high(high), PascalType(PascalType::TypeGroup::SUBRANGE) {}

    llvm::ConstantInt *ArrayType::getLLVMLow(llvm::LLVMContext &context) {
        return llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), range.first, true);
    }

    llvm::ConstantInt *ArrayType::getLLVMHigh(llvm::LLVMContext &context) {
        return llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), range.second, true);
    }

    ArrayType::ArrayType(std::pair<int, int> range, PascalType *type) :
            range(range), element_type(type), PascalType(PascalType::TypeGroup::ARRAY) {}

    StrType::StrType(int dim) : dim(dim), PascalType(PascalType::TypeGroup::STR) {}

    RecordType::RecordType(std::vector<std::string> name_vec, std::vector<PascalType *> type_vec) :
            name_vec(name_vec), type_vec(type_vec), PascalType(PascalType::TypeGroup::RECORD) {
        this->size = name_vec.size();
    }

    bool isEqual(const PascalType *const a, const PascalType *const b) {
        if (a->tg != b->tg) return false;
        if (a->tg == PascalType::TypeGroup::BUILT_IN)
            return ((BuiltinType *) a)->type == ((BuiltinType *) b)->type;
        else
            return true;
    }

    llvm::Type *getLLVMType(llvm::LLVMContext &context, PascalType *const p_type) {
        if (p_type->tg == PascalType::TypeGroup::BUILT_IN) {

            if (isEqual(p_type, INT_TYPE))
                return llvm::Type::getInt32Ty(context);
            else if (isEqual(p_type, REAL_TYPE))
                return llvm::Type::getDoubleTy(context);
            else if (isEqual(p_type, CHAR_TYPE))
                return llvm::Type::getInt8Ty(context);
            else if (isEqual(p_type, BOOLEAN_TYPE))
                return llvm::Type::getInt1Ty(context);
            else if (isEqual(p_type, VOID_TYPE))
                return llvm::Type::getVoidTy(context);
            else
                return nullptr;

        } else if (p_type->tg == PascalType::TypeGroup::STR) {

            StrType *str = (StrType *) p_type;
            return llvm::ArrayType::get(getLLVMType(context, CHAR_TYPE), (uint64_t) (str->dim));

        } else if (p_type->tg == PascalType::TypeGroup::ARRAY) {

            ArrayType *array = (ArrayType *) p_type;
            llvm::ArrayType *ret = nullptr;
            int len = array->range.second - array->range.first + 1;
            std::cout << "creating array of length " <<len << std::endl;
            ret = llvm::ArrayType::get(getLLVMType(context, array->element_type), (uint64_t) len);
            return ret;

        } else if (p_type->tg == PascalType::TypeGroup::RECORD) {

            RecordType *record = (RecordType *) p_type;
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

    BuiltinType::BuiltinType(BuiltinType::BasicTypes type) : type(type), PascalType(PascalType::TypeGroup::BUILT_IN) {}
}