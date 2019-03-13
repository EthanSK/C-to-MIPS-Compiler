#ifndef functionDeclaration_hpp
#define functionDeclaration_hpp

#include <iostream>
#include "statement.hpp"
#include "primitiveType.hpp"

class FunctionDeclaration : public Statement
{
public:
  FunctionDeclaration(PrimitiveType _primitiveType, std::string _name, StatementPtr parameters);
  StatementPtr getParameters() const;
  void printC(std::ostream &os) const override;

protected:
  std::string name;
  PrimitiveType primitiveType;
};

#endif