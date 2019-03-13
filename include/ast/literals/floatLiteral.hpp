#ifndef floatLiteral_hpp
#define floatLiteral_hpp

#include <iostream>
#include "literal.hpp"

class FloatLiteral : public Literal
{
private:
  float value;

public:
  FloatLiteral(float _value);
  void printC(std::ostream &os) const override;
};

#endif