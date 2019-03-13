#ifndef function_hpp
#define function_hpp

#include <iostream>
#include "statement.hpp"
#include "primitiveType.hpp"
#include "functionParameterList.hpp"

class Function : public Statement
{

public:
  virtual StatementPtr getParameters() const = 0; //virtual because implementation mIGHT be different for calls and definition because different number of branches
  virtual void printC(std::ostream &os) const = 0;

protected:
  Function(PrimitiveType _primitiveType, std::string _name) : name(_name){};
  std::string name;
  PrimitiveType primitiveType;
};

#endif