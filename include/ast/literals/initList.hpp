#ifndef initList_hpp
#define initList_hpp

#include <iostream>
#include <vector>

#include "literal.hpp"

/*

The parser should read init list literals recursively. {{5, 3}, 2, {{3, 3}, {5, 3}}} is valid
Init lists are used for structs, as well as arrays. (don't have to do unions)

*/

class InitList : public Literal //branches will be elements of the init list. elements will either be another init list or a terminal literal value
{
  public:
    void printC(std::ostream &os) const override;
};

#endif