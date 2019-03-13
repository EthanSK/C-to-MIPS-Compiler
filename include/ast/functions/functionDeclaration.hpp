#ifndef functionDeclaration_hpp
#define functionDeclaration_hpp

#include <iostream>
#include "statement.hpp"
#include "variableDeclaration.hpp"

class FunctionDeclaration : public VariableDeclaration //think about it, a function is a variable declaration just with parameters 
{
public:
  FunctionDeclaration(PrimitiveType _primitiveType, std::string _name, StatementPtr parameters);
  StatementPtr getParameters() const;
  void printC(std::ostream &os) const override;
};

#endif