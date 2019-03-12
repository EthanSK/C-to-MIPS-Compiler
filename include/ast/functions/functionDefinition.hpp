#ifndef functionDefinition_hpp
#define functionDefinition_hpp

#include <iostream>
#include "statement.hpp"
#include "function.hpp"

class FunctionDefinition : public Function
{
public:
  FunctionDefinition(StatementPtr parameters, StatementPtr scopeBlock);
  StatementPtr getParameters() const override;
  StatementPtr getScopeBlock() const;
  void printC(std::ostream &os) const override;
};

#endif