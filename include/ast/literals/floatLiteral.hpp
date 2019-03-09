#ifndef floatLiteral_hpp
#define floatLiteral_hpp

#include <iostream>
#include "literal.hpp"

class FloatLiteral : Literal
{
  public:
    float value;
    void printCode(std::ostream &os) const override;
};

#endif