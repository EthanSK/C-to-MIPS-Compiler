#ifndef stringLiteral_hpp
#define stringLiteral_hpp

#include <iostream>
#include "literal.hpp"

class StringLiteral : public Literal
{
private:
  std::string value;

public:
  StringLiteral(std::string value);
  std::string getValue() const;
  void printC(std::ostream &os) const override;
};

#endif