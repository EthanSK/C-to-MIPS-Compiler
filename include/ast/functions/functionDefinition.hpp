#ifndef functionDefinition_hpp
#define functionDefinition_hpp

#include <iostream>
#include "statement.hpp"

class FunctionDefinition : public Statement //definition is NOT just declaration with scope blokc, the decl params can just be type without name unlike in definiton.
{
public:
  FunctionDefinition(StatementPtr type, std::string name, StatementPtr parameters, StatementPtr scopeBlock);

  StatementPtr getType() const;
  StatementPtr getParameters() const;
  StatementPtr getScopeBlock() const;
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
  void printC(std::ostream &os) const override;
  std::string _name;
};

#endif