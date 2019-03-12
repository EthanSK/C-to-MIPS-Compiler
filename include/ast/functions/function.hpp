#ifndef function_hpp
#define function_hpp

#include <iostream>
#include "statement.hpp"
#include "functionParameterList.hpp"

class Function : public Statement
{
protected:
  std::string name;
public:
  virtual StatementPtr getParameters() const = 0; //virtual because implementation mIGHT be different for calls and definition because different number of branches
  virtual void printC(std::ostream &os) const = 0;
};

#endif