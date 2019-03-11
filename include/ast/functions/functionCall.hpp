#ifndef floatLiteral_hpp
#define floatLiteral_hpp

#include <iostream>
#include "literal.hpp"

class FloatLiteral : public Literal
{
  private:
    float value;
  public:
    float getValue() const;
    void printC(std::ostream &os) const override;
};

#endif