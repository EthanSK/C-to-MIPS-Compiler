#ifndef arrayVariable_hpp
#define arrayVariable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"
#include "primitiveType"
#include "variableDeclaration.hpp"

class PointerType : public PrimitiveType
{ //the value will be in an init list on the right branch of the binary op =
public:
  PointerType(Type _type) : PrimitiveType(_type){};
  //we don't need a typeToString method. think about it, when decoding in codegen, we use elementType and size info thats it
protected:
  void printC(std::ostream &os) const;
};

#endif
