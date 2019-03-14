#ifndef functionCall_hpp
#define functionCall_hpp

#include <iostream>
#include "statement.hpp"

class FunctionCall : public Statement
{
public:
  FunctionCall(std::string name, StatementPtr parameters); //parameters here won't be declarations even tho they use the func decl list (coz i'm lazy)
  StatementPtr getParameters() const;
  void printC(std::ostream &os) const override;

protected:
  std::string _name;
};

#endif