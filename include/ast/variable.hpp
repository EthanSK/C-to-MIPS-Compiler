#ifndef variable_hpp
#define variable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"

class Variable : Statement
{
  protected:
    virtual void printC(std::ostream &os) const = 0;
};

#endif
