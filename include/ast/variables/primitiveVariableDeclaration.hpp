#ifndef primitiveVariable_hpp
#define primitiveVariable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "variableDeclaration.hpp"

class PrimitiveVariableDeclaration : public VariableDeclaration
{
public:
  PrimitiveVariableDeclaration(PrimitiveType _primitiveType, std::string _name) : VariableDeclaration(_primitiveType, _name){};

protected:
  void printC(std::ostream &os) const;
};

#endif
