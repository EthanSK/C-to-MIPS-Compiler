#ifndef literal_hpp
#define literal_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class BinaryOperator : Statement
{
  protected:
    StatementPtr getLeft() const;
    StatementPtr getRight() const;
    virtual void printCode(std::ostream &os) const = 0; //prints c90 code so we can compare against input code //called in << overload
};

#endif
