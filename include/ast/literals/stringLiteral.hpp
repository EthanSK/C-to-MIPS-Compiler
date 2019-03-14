#ifndef stringLiteral_hpp
#define stringLiteral_hpp

#include <iostream>
#include "literal.hpp"

class StringLiteral : public Literal
{
public:
  StringLiteral(std::string value);
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
  void printC(std::ostream &os) const override;

private:
  std::string _value;
};

#endif