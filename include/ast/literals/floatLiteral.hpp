#ifndef floatLiteral_hpp
#define floatLiteral_hpp

#include <iostream>
#include "literal.hpp"

class FloatLiteral : public Literal
{
  public:
    float value;
    void printC(std::ostream &os) const override;
};

#endif