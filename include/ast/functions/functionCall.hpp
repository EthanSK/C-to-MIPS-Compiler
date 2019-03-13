#ifndef functionCall_hpp
#define functionCall_hpp

#include <iostream>
#include "function.hpp"
#include "functionParameterList.hpp"

class FunctionCall : public Function
{
public:
  FunctionCall(std::string _name, StatementPtr parameters); //parameters here won't be declarations even tho they use the func decl list (coz i'm lazy)
  StatementPtr getParameters() const override;
  void printC(std::ostream &os) const override;
};

#endif