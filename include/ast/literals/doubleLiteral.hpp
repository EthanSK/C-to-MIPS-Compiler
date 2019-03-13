#ifndef doubleLiteral_hpp
#define doubleLiteral_hpp

#include <iostream>
#include "literal.hpp"

class DoubleLiteral : public Literal
{
public:
    DoubleLiteral(double value);
    void printC(std::ostream &os) const override;

  private:
    double _value;
};

#endif