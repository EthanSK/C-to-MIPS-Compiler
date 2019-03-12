#ifndef functionDeclaration_hpp
#define functionDeclaration_hpp

#include <iostream>
#include "statement.hpp"
#include "function.hpp"

class FunctionDeclaration : public Function
{
public:
  FunctionDeclaration(StatementPtr parameters);
  StatementPtr getParameters() const override;
  void printC(std::ostream &os) const override;
};

#endif