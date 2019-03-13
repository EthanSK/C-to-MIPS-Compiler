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
  PrimitiveVariableDeclaration(std::string _name, PrimitiveType _primitiveType) : VariableDeclaration(_name, _primitiveType){};

protected:
  void printC(std::ostream &os) const;
};
 
#endif
