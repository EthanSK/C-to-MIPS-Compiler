#ifndef doubleLiteral_hpp
#define doubleLiteral_hpp

#include <iostream>
#include "literal.hpp"

class DoubleLiteral : public Literal
{
  public:
    DoubleLiteral(double value);
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    virtual int evalConst() const override { throw std::string("cannot evaluate a double literal to an integer"); }

  protected:
    void printC(std::ostream &os) const override;

  private:
    double _value;
};

#endif