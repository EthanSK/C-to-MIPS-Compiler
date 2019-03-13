#ifndef functionDefinition_hpp
#define functionDefinition_hpp

#include <iostream>
#include "statement.hpp"
#include "variableDeclaration.hpp"

class FunctionDefinition : public VariableDeclaration //definition is NOT just declaration with scope block (so don't inherit that), the decl params can just be type without name unlike in definiton int a(int,int,char) for eg.
{
public:
  FunctionDefinition(PrimitiveType _primitiveType, std::string _name, StatementPtr parameters, StatementPtr scopeBlock);
  StatementPtr getScopeBlock() const;
  StatementPtr getParameters() const;
  void printC(std::ostream &os) const override;

};

#endif