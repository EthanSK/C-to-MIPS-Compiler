#ifndef functionDeclaration_hpp
#define functionDeclaration_hpp

#include <iostream>
#include "statement.hpp"
#include "type.hpp"

class FunctionDeclaration : public Statement
{
public:
  FunctionDeclaration(StatementPtr type, std::string name, StatementPtr parameters);
  StatementPtr getParameters() const;
  StatementPtr getType() const;
  void printC(std::ostream &os) const override;

protected:
  std::string _name;
};

#endif