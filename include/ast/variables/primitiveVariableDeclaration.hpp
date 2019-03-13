#ifndef primitiveVariable_hpp
#define primitiveVariable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "variableDeclaration.hpp"

enum class PrimitiveType //enum class not enum so we guarantee strongly typed
{
  _int,
  _float,
  _double,
  _char,
  _unsigned
  //these are all we need appaz
};

class PrimitiveVariableDeclaration : public VariableDeclaration
{
public:
  PrimitiveVariableDeclaration(PrimitiveType _type, std::string name) : VariableDeclaration(name), primitiveType(_type){}; //must be init'ed with a primitiveType value or makes no sense
  std::string primitiveTypeToString() const;

protected:
  PrimitiveType primitiveType;
  void printC(std::ostream &os) const;
};

#endif
