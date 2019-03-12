#ifndef variableDeclarationList_hpp 
#define variableDeclarationList_hpp

#include <iostream>
#include <vector>

#include "variableDeclaration.hpp"

class VariableDeclarationList: public Statement//can be used for functions param list and struct fields
{
  public:
    VariableDeclarationList(std::vector<StatementPtr> variableDeclarations);
    std::vector<StatementPtr> getVariableDeclarations() const;
    virtual void printC(std::ostream &os) const override = 0;
};

#endif