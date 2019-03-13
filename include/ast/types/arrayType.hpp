#ifndef arrayType_hpp
#define arrayType_hpp

#include "primitiveType.hpp"

class ArrayType : public PrimitiveType
{ //wrapper class for the enum type
  protected:
    int size;
    void printC(std::ostream &os) const override;
};

#endif