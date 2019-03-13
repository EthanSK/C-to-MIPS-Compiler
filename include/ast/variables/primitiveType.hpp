#ifndef primitiveType_hpp
#define primitiveType_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"
#include "variableDeclaration.hpp"

class PrimitiveType : public Statement //wrapper class for the enum. is a lang defined keyword so is a node not property of vardecl
{
public:
  enum class Type //enum class not enum so we guarantee strongly typed
  {
    _int,
    _float,
    _double,
    _char,
    _unsigned
    //these are all we need appaz
  };
  Type type;
  std::string name;
  PrimitiveType(Type _type) : type(_type){};
  std::string typeToString() const;

protected:
  void printC(std::ostream &os) const;
};

#endif
