#ifndef doWhileLoop_hpp
#define doWhileLoop_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class DoWhileLoop : public Statement //will have branch[0] execution block branch[1] condition block
{

public:
  DoWhileLoop(StatementPtr scopeBlock, StatementPtr condition);

protected:
  StatementPtr getScopeBlock() const;
  StatementPtr getCondition() const;
  virtual void printC(std::ostream &os) const = 0;
};

#endif
