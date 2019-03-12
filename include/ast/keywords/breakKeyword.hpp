#ifndef breakKeyword_hpp
#define breakKeyword_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class BreakKeyword : public Statement //will have branch[0] execution block branch[1] condition block
{
    //has no braches and carries no data
  protected:
    virtual void printC(std::ostream &os) const = 0;
};

#endif
