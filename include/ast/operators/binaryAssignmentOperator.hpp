#ifndef binaryAssignmentOperator_hpp
#define binaryAssignmentOperator_hpp

#include "binaryOperator.hpp"

class BinaryAssignmentOperator : public BinaryOperator
{
public:
  using BinaryOperator::BinaryOperator;
  virtual bool isConstant() const override { return false; }
  virtual int evalConst() const override { throw "cannot statically evaluate an assignment"; }

};

#endif
