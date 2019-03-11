#ifndef arrayVariable_hpp
#define arrayVariable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"
#include "primitiveVariable.hpp" 
#include "variable.hpp"

class ArrayVariableDeclaration : public VariableDeclaration {//the value will be in an init list on the right branch of the binary op =
public:
  PrimitiveVariableDeclaration::Type elementType;
  int size;
  ArrayVariableDeclaration(PrimitiveVariableDeclaration::Type _elementType, int _size) : elementType(_elementType), size(_size){};
  //we don't need a typeToString method. think about it, when decoding in codegen, we use elementType and size info thats it
protected:
  void printC(std::ostream &os) const;
};

#endif
