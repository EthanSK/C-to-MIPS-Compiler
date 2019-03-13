#ifndef arrayElementReference_hpp
#define arrayElementReference_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "variableReference.hpp"

class ArrayElementReference : public VariableReference
{
  public:
    ArrayElementReference(std::string _name, int _index) : VariableReference(_name), index(_index){};
  protected:
    int index;
    void printC(std::ostream &os) const;
};

#endif
