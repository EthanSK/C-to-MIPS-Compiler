#ifndef integerLiteral_hpp
#define integerLiteral_hpp

#include <iostream>
#include "literal.hpp"

class IntegerLiteral : public Literal
{
public:
  IntegerLiteral(int value);
  void printC(std::ostream &os) const override;

private:
  int _value;
};

#endif