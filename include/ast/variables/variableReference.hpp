#ifndef variable_hpp
#define variable_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "literal.hpp"

class VariableReference : public Statement 
{
  protected:
    std::string name; 
    void printC(std::ostream &os) const override; 
    
};

#endif
