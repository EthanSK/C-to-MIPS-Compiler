#ifndef pointerType_hpp
#define pointerType_hpp

#include "primitiveType.hpp"

class PointerType : public PrimitiveType
{ //wrapper class for the enum type
  protected:
    void printC(std::ostream &os) const override;
};

#endif