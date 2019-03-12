#ifndef doubleLiteral_hpp
#define doubleLiteral_hpp

#include <iostream>
#include "literal.hpp"

class DoubleLiteral : public Literal
{
  private:
    double value;
  public:
    DoubleLiteral(double _value);
    double getValue() const;
    void printC(std::ostream &os) const override;
};

#endif