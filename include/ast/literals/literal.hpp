#ifndef literal_hpp
#define literal_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class Literal : public Statement //Literal is an interface for all the literal types
{
  protected:
    virtual void printC(std::ostream &os) const = 0;
};

#endif
