#ifndef literal_hpp
#define literal_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class Literal : Statement //Literal is an interface for all the literal types
{
  protected:
    virtual void printCode(std::ostream &os) const = 0;
};

#endif
