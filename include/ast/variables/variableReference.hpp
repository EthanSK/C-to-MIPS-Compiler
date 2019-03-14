#ifndef variableReference_hpp
#define variableReference_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class VariableReference : public Statement
{
public:
  VariableReference(std::string name);
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
  std::string _name;
  void printC(std::ostream &os) const override;
};

#endif
