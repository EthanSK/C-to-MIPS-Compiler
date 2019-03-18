#ifndef variableReference_hpp
#define variableReference_hpp

#include <string>
#include <iostream>
#include "statement.hpp"
#include "identifier.hpp"

class VariableReference : public Statement
{
public:
  VariableReference(StatementPtr name);
  VariableReference(std::string name) : VariableReference(new Identifier(name)) { } 
  StatementPtr getName() const;
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
  void printC(std::ostream &os) const override;
};

#endif
