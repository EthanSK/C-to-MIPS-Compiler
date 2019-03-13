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
  ArrayVariableDeclaration(std::string _name, PrimitiveType _primitiveType, int _size) : VariableDeclaration(_name, _primitiveType), size(_size){}; 
  //we don't need a typeToString method. think about it, when decoding in codegen, we use elementType and size info thats it
  PrimitiveType getPrimitiveType() const;

protected:
  int size;
  void printC(std::ostream &os) const;
}; 

#endif
