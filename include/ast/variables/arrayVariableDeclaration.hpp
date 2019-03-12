#ifndef arrayVariable_hpp
#define arrayVariable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"
#include "primitiveVariableDeclaration.hpp" 
#include "variableDeclaration.hpp"

class ArrayVariableDeclaration : public VariableDeclaration {//the value will be in an init list on the right branch of the binary op =
public:
  PrimitiveType elementType;
  int size;
  ArrayVariableDeclaration(PrimitiveType _elementType, int _size, std::string name) : elementType(_elementType), size(_size), VariableDeclaration(name){};
  //we don't need a typeToString method. think about it, when decoding in codegen, we use elementType and size info thats it
protected:
  void printC(std::ostream &os) const;
};

#endif
