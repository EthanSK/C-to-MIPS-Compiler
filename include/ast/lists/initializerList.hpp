#ifndef initList_hpp
#define initList_hpp

#include <iostream>
#include <vector>

#include "literal.hpp"

/*

The parser should read init list literals recursively. {{5, 3}, 2, {{3, 3}, {5, 3}}} is valid
Init lists are used for structs, as well as arrays. (don't have to do unions)

*/

class InitializerList : public Statement
{
  public:

    std::vector<StatementPtr> getElements() const;
    void printC(std::ostream &os) const override;
};

#endif