#ifndef variableDeclarationList_hpp 
#define variableDeclarationList_hpp

#include <iostream>
#include <vector>

#include "literal.hpp"


class VariableDeclarationList: public Statement
{
  public:

    std::vector<StatementPtr> getElements() const;
    void printC(std::ostream &os) const override;
};

#endif