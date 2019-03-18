#ifndef declarator_hpp
#define declarator_hpp

#include "statement.hpp"

class Declarator : public Statement
{
  protected:
    virtual void printC(std::ostream &os) const = 0;
};

#endif