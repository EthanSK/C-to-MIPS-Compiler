#ifndef functionParameterList_hpp 
#define functionParameterList_hpp

#include <iostream>
#include <vector>

#include "variableDeclarationList.hpp"

class FunctionParameterList : public VariableDeclarationList//can be used for functions param list and struct fields
{
  public:
    void printC(std::ostream &os) const override;
};

#endif