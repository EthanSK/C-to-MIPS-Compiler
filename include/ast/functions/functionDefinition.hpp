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
  void printC(std::ostream &os) const override;

protected:
  std::string _name;
};

#endif