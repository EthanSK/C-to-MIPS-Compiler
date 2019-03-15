#ifndef functionParameterList_hpp 
#define functionParameterList_hpp

#include <iostream>
#include <vector>

#include "variableDeclarationList.hpp"
//can be used for both function definition and function call because the var declaration list does the same thing even tho its not technically the same thing
class FunctionParameterList : public VariableDeclarationList//can be used for functions param list and struct fields
{
  using VariableDeclarationList::VariableDeclarationList;
  public:
    void printC(std::ostream &os) const override;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
};

#endif