#ifndef variable_hpp
#define variable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"

class Variable : public Statement //if variable was declared with literal value, it will be the branches[0]
{
  protected:
    std::string name; 
    virtual void printC(std::ostream &os) const = 0; 
};

#endif
