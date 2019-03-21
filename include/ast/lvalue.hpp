#ifndef lvalue_hpp
#define lvalue_hpp

#include <vector>
#include "context.hpp"
#include "ILinstr.hpp"

class LValue;
typedef const LValue *LValuePtr;

class LValue
{
public:
    virtual void generateLValueStoreIL(std::vector<ILinstr> &instrs, ILContext &context, std::string inputReg) const = 0;
};

#endif