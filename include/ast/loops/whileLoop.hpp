#ifndef whileLoop_hpp
#define whileLoop_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class WhileLoop : public Statement //will have branch[0] condition branch[1] execution block
{
public:
  WhileLoop(StatementPtr condition, StatementPtr scopeBlock);
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  void generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const override;

protected:
  StatementPtr getCondition() const;
  StatementPtr getScopeBlock() const;

  virtual void printC(std::ostream &os) const override;
};

#endif
