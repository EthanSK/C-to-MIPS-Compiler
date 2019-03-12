#ifndef functionDefinition_hpp
#define functionDefinition_hpp

#include <iostream>
#include "statement.hpp"
#include "function.hpp"

class FunctionDefinition : public Function
{
public:
  StatementPtr getParameters() const override;
  StatementPtr getScopeBlock() const;
  void printC(std::ostream &os) const override;
};

#endif