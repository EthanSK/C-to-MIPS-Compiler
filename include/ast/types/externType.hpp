#ifndef externType_hpp
#define externType_hpp

#include "primitiveType.hpp"

class ExternType : public PrimitiveType
{ //wrapper class for the enum type
  protected:
    void printC(std::ostream &os) const override;
};

#endif