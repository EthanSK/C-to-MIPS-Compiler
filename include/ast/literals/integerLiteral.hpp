#ifndef integerLiteral_hpp
#define integerLiteral_hpp

#include <iostream>
#include "literal.hpp"

class IntegerLiteral : public Literal
{
private:
  int value;

public:
  int getValue() const;
  void printC(std::ostream &os) const override;
};

#endif