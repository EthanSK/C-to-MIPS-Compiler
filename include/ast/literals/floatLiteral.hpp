#ifndef floatLiteral_hpp
#define floatLiteral_hpp

#include <iostream>
#include "literal.hpp"

class FloatLiteral : public Literal
{
public:
  FloatLiteral(float value);
  void printC(std::ostream &os) const override;

private:
  float _value;
};

#endif