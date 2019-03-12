
#ifndef unaryOperator_hpp
#define unaryOperator_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class UnaryOperator : public Statement
{
public:
  UnaryOperator(StatementPtr operand);

protected:
  StatementPtr getOperand() const;
  virtual void printC(std::ostream &os) const = 0; //prints c90 code so we can compare against input code //called in << overload
};

#endif
