#ifndef structDefinitionList_hpp
#define structDefinitionList_hpp

#include <iostream>
#include <vector>

#include "variableDeclarationList.hpp"

class StructDefinitionList : public VariableDeclarationList//can be used for functions param list and struct fields
{
  using VariableDeclarationList::VariableDeclarationList;
  public:
    void printC(std::ostream &os) const override;
};

#endif