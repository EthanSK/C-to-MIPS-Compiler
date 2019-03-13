#ifndef stringLiteral_hpp
#define stringLiteral_hpp

#include <iostream>
#include "literal.hpp"

class StringLiteral : public Literal
{
public:
  StringLiteral(std::string value);
  void printC(std::ostream &os) const override;

private:
  std::string _value;
};

#endif