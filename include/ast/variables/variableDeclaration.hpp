#ifndef variableDeclaration_hpp
#define variableDeclaration_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "identifier.hpp"

class VariableDeclaration : public Statement
{
public:
  VariableDeclaration(StatementPtr type, StatementPtr name);
  VariableDeclaration(StatementPtr type, std::string name) : VariableDeclaration(type, new Identifier(name)) { }
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  StatementPtr getType() const;
  StatementPtr getName() const;
  
protected:
  virtual void printC(std::ostream &os) const override;
};

#endif
