#ifndef variable_hpp
#define variable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "primitiveType.hpp"

class VariableDeclaration : public Statement
{
public:
  VariableDeclaration(StatementPtr type, std::string name);
  StatementPtr getType() const;
protected:
  std::string _name;
  virtual void printC(std::ostream &os) const;
};

#endif
