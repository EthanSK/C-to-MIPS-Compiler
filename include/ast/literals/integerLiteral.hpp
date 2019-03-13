#ifndef integerLiteral_hpp
#define integerLiteral_hpp

#include <iostream>
#include "literal.hpp"

class IntegerLiteral : public Literal
{
private:
  int value;

public:
  IntegerLiteral(int _value);
  void printC(std::ostream &os) const override;
};

#endif