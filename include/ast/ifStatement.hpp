#ifndef ifStatement_hpp
#define ifStatement_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class IfStatement : Statement //will have branch[0] condition, branch[1] if block, and branch[2] else block
{
  protected:
    virtual void printCode(std::ostream &os) const = 0;
};

#endif
