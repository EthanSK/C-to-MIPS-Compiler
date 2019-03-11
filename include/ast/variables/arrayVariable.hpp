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

class ArrayVariable : public Variable //the branches contain the literal value if anythnig, which is most likely going to be an init list
{
public:
  PrimitiveVariable::Type elementType;
  int size;
  ArrayVariable(PrimitiveVariable::Type _elementType, int _size) : elementType(_elementType), size(_size){};
  //we don't need a typeToString method. think about it, when decoding in codegen, we use elementType and size info thats it
protected:
  void printC(std::ostream &os) const;
};

#endif
