#ifndef primitiveVariable_hpp
#define primitiveVariable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"
#include "variableDeclaration.hpp"

enum class PrimitiveType //enum class not enum so we guarantee strongly typed
{
  _int,
  _float,
  _double
};

class PrimitiveVariableDeclaration : public VariableDeclaration
{
public:
  PrimitiveType type;
  PrimitiveVariableDeclaration(PrimitiveType _type, std::string name) :  VariableDeclaration(name), type(_type){}; //must be init'ed with a type value or makes no sense
  std::string typeToString() const;

protected:
  void printC(std::ostream &os) const;
};

#endif
