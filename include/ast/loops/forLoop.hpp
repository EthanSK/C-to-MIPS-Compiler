#ifndef forLoop_hpp
#define forLoop_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class ForLoop : public Statement //will have branch[0] initializatino,, branch[1] condition, branch[2] increment/decr, branch[3] execution block
{
public:
  ForLoop(StatementPtr init, StatementPtr condition, StatementPtr increment, StatementPtr scopeBlock);
  void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;

protected:
  StatementPtr getInit() const;
  StatementPtr getCondition() const;
  StatementPtr getIncrement() const;
  StatementPtr getScopeBlock() const;

  virtual void printC(std::ostream &os) const override;
};

#endif
