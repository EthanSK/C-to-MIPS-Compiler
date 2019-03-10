#ifndef variable_hpp
#define variable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"

class Variable : Statement //if variable was declared with literal value, it will be the branches[0]
{
  public:
   std::string type; //indicateds if its an int, float, char[69], 'float (*[42])(float, float, etc...

  protected: 
    virtual void printC(std::ostream &os) const = 0; 
};

#endif
