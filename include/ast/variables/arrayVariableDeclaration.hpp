#ifndef arrayVariable_hpp
#define arrayVariable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "variableDeclaration.hpp"
#include "primitiveType.hpp"

class ArrayVariableDeclaration : public VariableDeclaration
{ //the value will be in an init list on the right branch of the binary op =
public:
  ArrayVariableDeclaration(PrimitiveType _primitiveType, std::string _name, int _size) : VariableDeclaration(_primitiveType, _name), size(_size){};

protected:
  int size;
  void printC(std::ostream &os) const;
};

#endif
