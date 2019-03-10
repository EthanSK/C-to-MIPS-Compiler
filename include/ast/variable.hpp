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
    enum VariableType//can be accessed outside this classe using Variable::VariableType or straight cases as Variable::_float;
    { //sholud have helper function to convert to string value
        _int, //can't use C++ keywords as enum cases
        _float
    };
    VariableType variableType;

    Variable(VariableType _variableType) : variableType(_variableType) {}  

    std::string typeToString();

  protected: 
    virtual void printC(std::ostream &os) const = 0; 
};

#endif
