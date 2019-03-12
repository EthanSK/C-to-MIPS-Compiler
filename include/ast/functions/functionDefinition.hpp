#ifndef functionDefinition_hpp
#define functionDefinition_hpp

#include <iostream>
#include "statement.hpp"
#include "functionParameterList.hpp"
#include "scopeBlock.hpp"

class FunctionDeclaration : public Statement 
{
  public:
    FunctionParameterList getParameters() const;
    ScopeBlock getScopeBlock() const;
    void printC(std::ostream &os) const override;
};

#endif