#ifndef primitiveVariable_hpp
#define primitiveVariable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"
#include "variable.hpp"

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
  PrimitiveVariableDeclaration(Type _type) : type(_type){}; //must be init'ed with a type value or makes no sense
  std::string typeToString() const;

protected:
  void printC(std::ostream &os) const;
};

#endif
