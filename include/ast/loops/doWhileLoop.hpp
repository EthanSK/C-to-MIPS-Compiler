#ifndef doWhileLoop_hpp
#define doWhileLoop_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class DoWhileLoop : Statement //will have branch[0] execution block branch[1] condition block
{
  protected:
    virtual void printCode(std::ostream &os) const = 0;
};

#endif
