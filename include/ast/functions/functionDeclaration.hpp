#ifndef functionDeclaration_hpp
#define functionDeclaration_hpp

#include <iostream>
#include "statement.hpp"
#include "functionParameterList.hpp"

class FunctionDeclaration : public Statement 
{
  public:
    FunctionParameterList getParameters() const;
    void printC(std::ostream &os) const override;
};

#endif