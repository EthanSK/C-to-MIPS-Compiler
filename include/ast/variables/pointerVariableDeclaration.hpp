#ifndef pointerVariableDeclaration_hpp
#define pointerVariableDeclaration_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "primitiveVariableDeclaration.hpp"
#include "variableDeclaration.hpp"

class PointerVariableDeclaration : public VariableDeclaration
{ //the value will be in an init list on the right branch of the binary op =
  public:
    PointerVariableDeclaration(std::string name, PrimitiveType _primitiveType) : VariableDeclaration(name), primitiveType(_primitiveType){};
    //we don't need a typeToString method. think about it, when decoding in codegen, we use elementType and size info thats it

  protected:
    PrimitiveType primitiveType;
    void printC(std::ostream &os) const;
};

#endif
