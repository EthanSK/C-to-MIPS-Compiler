#ifndef sequenceBlock_hpp
#define sequenceBlock_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class SequenceBlock : public Statement
{
public:
  SequenceBlock();
  SequenceBlock(StatementPtr branch);
  SequenceBlock(std::vector<StatementPtr> branches);
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override; 

protected:
  virtual void printC(std::ostream &os) const override;
};

#endif
