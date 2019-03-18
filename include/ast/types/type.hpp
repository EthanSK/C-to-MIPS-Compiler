#ifndef type_hpp
#define type_hpp

#include "statement.hpp"

class Type;
typedef const Type* TypePtr;

class Type : public Statement
{
  public:
    virtual int getTypeSize() const = 0;

  protected:
    virtual void printC(std::ostream &os) const = 0;
};

#endif