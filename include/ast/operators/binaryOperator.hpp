#ifndef binaryOperator_hpp
#define binaryOperator_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "rvalue.hpp"

class BinaryOperator : public Statement, public RValue
{
public:
  BinaryOperator(StatementPtr left, StatementPtr right);
  virtual bool isConstant() const override;
 
protected:
  StatementPtr getLeft() const;
  StatementPtr getRight() const;
  RValuePtr getLeftR() const;
  RValuePtr getRightR() const;
  virtual void printC(std::ostream &os) const = 0; //prints c90 code so we can compare against input code //called in << overload
};

#endif
