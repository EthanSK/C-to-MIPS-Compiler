#ifndef breakKeyword_hpp
#define breakKeyword_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class BreakKeyword : public Statement
{
  //has no braches and carries no data
public:
  void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;

protected:
  virtual void printC(std::ostream &os) const override;
};

#endif
