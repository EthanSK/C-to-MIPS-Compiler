#ifndef stringLiteral_hpp
#define stringLiteral_hpp

#include <iostream>
#include "literal.hpp"

class StringLiteral : Literal
{
  public:
    std::string value;
    void printCode(std::ostream &os) const override;
};

#endif