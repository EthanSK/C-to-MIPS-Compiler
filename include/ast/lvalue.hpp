#ifndef lvalue_hpp
#define lvalue_hpp

#include <vector>
#include "ilContext.hpp"
#include "instr.hpp"

class LValue;
typedef const LValue *LValuePtr;

class LValue
{
public:
    virtual void generateLValueStoreIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const = 0;
};

#endif