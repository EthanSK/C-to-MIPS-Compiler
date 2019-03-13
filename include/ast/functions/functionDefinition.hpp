#ifndef functionDefinition_hpp
#define functionDefinition_hpp

#include <iostream>
#include "statement.hpp"
#include "function.hpp"
#include "primitiveVariableDeclaration.hpp"

class FunctionDefinition : public Function
{
public:
  FunctionDefinition(PrimitiveType _primitiveType, std::string _name, StatementPtr parameters, StatementPtr scopeBlock);
  StatementPtr getParameters() const override;
  StatementPtr getScopeBlock() const;
  void printC(std::ostream &os) const override;

protected:
  std::string name;
};

#endif