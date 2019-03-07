#ifndef doubleLiteral_hpp
#define doubleLiteral_hpp

#include <iostream>
#include "literal.hpp"

class DoubleLiteral : Literal
{
  public:
    double value;
    void printCode(std::ostream &os) const override;
};

#endif