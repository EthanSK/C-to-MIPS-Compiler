#ifndef functionCall_hpp
#define functionCall_hpp

#include <iostream>
#include "functionParameterList.hpp"

class FunctionCall : public Statement
{
public:
  FunctionParameterList getParameters() const;
  void printC(std::ostream &os) const override;
};

#endif