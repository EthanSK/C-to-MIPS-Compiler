#ifndef doubleLiteral_hpp
#define doubleLiteral_hpp

#include <iostream>
#include "literal.hpp"

class DoubleLiteral : public Literal
{
  public:
    double value;
    void printC(std::ostream &os) const override;
};

#endif