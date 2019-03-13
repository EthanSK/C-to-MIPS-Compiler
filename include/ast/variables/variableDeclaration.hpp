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
  VariableDeclaration(PrimitiveType _primitiveType, std::string _name ) : name(_name), primitiveType(_primitiveType){};
  std::string primitiveTypeToString() const;

protected:
  std::string name;
  PrimitiveType primitiveType;

  virtual void printC(std::ostream &os) const = 0;
};

#endif
