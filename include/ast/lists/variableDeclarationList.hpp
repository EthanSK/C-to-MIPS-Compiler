#ifndef variableDeclarationList_hpp 
#define variableDeclarationList_hpp

#include <iostream>
#include <vector>

#include "literal.hpp"


class VariableDeclarationList: public Statement//can be used for functions param list and struct fields
{
  public:

    std::vector<StatementPtr> getVariables() const;
    virtual void printC(std::ostream &os) const override = 0;
};

#endif