#ifndef integerLiteral_hpp
#define integerLiteral_hpp

#include <iostream>
#include "literal.hpp"

class IntegerLiteral : public Literal
{
  public:
    int value;
    void printC(std::ostream &os) const override;
};

#endif