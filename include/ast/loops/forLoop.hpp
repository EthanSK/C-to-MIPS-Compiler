#ifndef forLoop_hpp
#define forLoop_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class ForLoop : Statement //will have branch[0] initializatino,, branch[1] condition, branch[2] increment/decr, branch[3] execution block
{
  protected:
    virtual void printC(std::ostream &os) const = 0;
};

#endif
