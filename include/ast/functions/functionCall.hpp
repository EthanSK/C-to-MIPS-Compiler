#ifndef functionCall_hpp
#define functionCall_hpp

#include <iostream>
#include "function.hpp"
#include "functionParameterList.hpp"

class FunctionCall : public Function
{
public:
  StatementPtr getParameters() const override;
  void printC(std::ostream &os) const override;
};

#endif