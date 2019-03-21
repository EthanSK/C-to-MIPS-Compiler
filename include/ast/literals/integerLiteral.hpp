#ifndef integerLiteral_hpp
#define integerLiteral_hpp

#include <iostream>
#include "literal.hpp"

class IntegerLiteral : public Literal
{
  public:
    IntegerLiteral(int value);
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const override; 

  protected:
    void printC(std::ostream &os) const override;

  private:
    int _value;
};

#endif