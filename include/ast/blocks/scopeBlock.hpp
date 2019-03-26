#ifndef scopeBlock_hpp
#define scopeBlock_hpp

#include "sequenceBlock.hpp"

class ScopeBlock : public SequenceBlock //aka compound statement, used to represent content between curly braces everywhere eg loops, conditions, pure scope, etc...
{
public:
  using SequenceBlock::SequenceBlock;
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  virtual void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override; 

protected:
  void printC(std::ostream &os) const override;
};

#endif
