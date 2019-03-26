#ifndef initList_hpp
#define initList_hpp

#include <iostream>
#include <vector>

#include "literal.hpp"

class InitializerList;
typedef const InitializerList* InitializerListPtr;

class InitializerList : public Statement
{
  public:
    InitializerList(std::vector<StatementPtr> elements);
    std::vector<StatementPtr> getElements() const;
    void printC(std::ostream &os) const override;
    bool isConstant() const;
};

#endif