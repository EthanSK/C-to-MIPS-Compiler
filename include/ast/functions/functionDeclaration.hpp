#ifndef functionDeclaration_hpp
#define functionDeclaration_hpp

#include <iostream>
#include "statement.hpp"
#include "identifier.hpp"

class FunctionDeclaration : public Statement
{
public:
  FunctionDeclaration(StatementPtr type, StatementPtr name, StatementPtr parameters);
  FunctionDeclaration(StatementPtr type, std::string name, StatementPtr parameters) : FunctionDeclaration(type, new Identifier(name), parameters) { }
  StatementPtr getParameters() const;
  StatementPtr getName() const;
  StatementPtr getType() const;

protected:
  void printC(std::ostream &os) const override;
};

#endif