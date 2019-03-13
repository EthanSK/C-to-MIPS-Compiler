#ifndef functionDeclaration_hpp
#define functionDeclaration_hpp

#include <iostream>
#include "statement.hpp"
#include "function.hpp"
#include "variableDeclaration.hpp"

class FunctionDeclaration : public Function
{
public:
  FunctionDeclaration(VariableDeclaration _primitiveType, std::string _name, StatementPtr parameters);
  StatementPtr getParameters() const override;
  void printC(std::ostream &os) const override;

protected:
  VariableDeclaration variableDeclaration;
};

#endif