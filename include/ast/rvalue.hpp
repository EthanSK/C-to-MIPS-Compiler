#ifndef rvalue_hpp
#define rvalue_hpp

class RValue;
typedef const RValue *RValuePtr;

class RValue
{
public:
    virtual bool isConstant() const = 0;
    virtual int evalConst() const = 0;
};

#endif