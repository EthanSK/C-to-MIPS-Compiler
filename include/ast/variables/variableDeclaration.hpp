#ifndef variable_hpp
#define variable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"

class VariableDeclaration : public Statement
{
public:
  VariableDeclaration(std::string name);

protected:
  std::string name;
  virtual void printC(std::ostream &os) const = 0;
};

#endif
