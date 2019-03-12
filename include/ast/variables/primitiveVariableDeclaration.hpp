#ifndef primitiveVariable_hpp
#define primitiveVariable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"
#include "variableDeclaration.hpp"

class PrimitiveVariableDeclaration : public VariableDeclaration 
{
public:
  enum class Type //enum class not enum so we guarantee strongly typed
  {
    _int,
    _float,
    _double
  };
  Type type;
  PrimitiveVariableDeclaration(Type _type, std::string name) : type(_type), VariableDeclaration(name) {};  //must be init'ed with a type value or makes no sense
  std::string typeToString() const;

protected:
  void printC(std::ostream &os) const;
};

#endif
