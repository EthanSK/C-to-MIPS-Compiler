#ifndef ifStatement_hpp
#define ifStatement_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "scopeBlock.hpp"

class IfElseStatement : public Statement //will have branch[0] condition, branch[1] if block, and branch[2] else block
{
public:
  IfElseStatement(StatementPtr condition, StatementPtr ifScopeBlock, StatementPtr elseScopeBlock);

protected:
  StatementPtr getCondition() const;
  StatementPtr getIfScopeBlock() const;
  StatementPtr getElseScopeBlock() const;

  void printC(std::ostream &os) const override;
};

#endif
