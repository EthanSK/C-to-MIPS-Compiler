#ifndef whileLoop_hpp
#define whileLoop_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class WhileLoop : public Statement //will have branch[0] condition branch[1] execution block
{
  protected:
    virtual void printC(std::ostream &os) const = 0;
};

#endif
