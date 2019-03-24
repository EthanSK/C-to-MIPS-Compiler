#ifndef emptyNode_hpp
#define emptyNode_hpp

#include "statement.hpp"

class EmptyNode : public Statement
{
public:
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override { os << "pass"; }
  void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override { }

protected:
  void printC(std::ostream &os) const override { }
};

#endif