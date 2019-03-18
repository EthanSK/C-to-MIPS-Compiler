#ifndef type_hpp
#define type_hpp

#include "statement.hpp"

class Type;
typedef const Type* TypePtr;

class Type : public Statement
{
  protected:
    virtual void printC(std::ostream &os) const = 0;
};

#endif