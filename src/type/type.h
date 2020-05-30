#ifndef OPC_TYPE_H
#define OPC_TYPE_H

#include <vector>
#include <map>
#include <llvm/IR/Type.h>
#include <llvm/IR/Constant.h>
#include <llvm/IR/Constants.h>
#include "../generator/generator.h"
#include <stdint.h>
#include <generator/generator.h>

namespace OurType {

    bool isEqual(const PascalType *const a, const PascalType *const b);

    class PascalType {
    public:
        enum class TypeGroup {
            BUILT_IN, ENUM, SUBRANGE, ARRAY, STR, RECORD
        };
        TypeGroup tg;

        PascalType(TypeGroup tg) : tg(tg) {}

        bool isSimple() const;

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
        enum class BasicTypes {
            INT, REAL, CHAR, BOOLEAN, VOID
        };
        BasicTypes type;

        BuiltinType(BasicTypes type) : type(type), PascalType(PascalType::TypeGroup::BUILT_IN) {};
    };

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


    class SubRangeType : public PascalType {
    public:
//    std::string type_name;
        int low;
        int high;

        SubRangeType(int low, int high);
    };


    class ArrayType : public PascalType {
    public:
        std::pair<int, int> range; // pair(low, high)
        PascalType *element_type;

        llvm::ConstantInt *getLLVMLow(llvm::LLVMContext &context);

        llvm::ConstantInt *getLLVMHigh(llvm::LLVMContext &context);

        ArrayType(std::pair<int, int> range, PascalType *type);
    };

    class StrType : public PascalType {
    public:
        int dim;

        StrType(int dim);
    };

    class RecordType : public PascalType {
    public:
        int size;
        std::vector<std::string> name_vec;
        std::vector<PascalType *> type_vec;

        RecordType(std::vector<std::string> name_vec, std::vector<PascalType *> type_vec);
    };

    class EnumType : public PascalType {
    public:
        std::vector<std::string> names_;

        EnumType(std::vector<std::string> names, Generator *g);
    };

    llvm::Type *getLLVMType(llvm::LLVMContext &context, PascalType *const p_type);

}; // namespace Type

#endif //OPC_TYPE_H