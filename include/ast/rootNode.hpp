#ifndef rootNode_hpp
#define rootNode_hpp

#include "statement.hpp"

class RootNode : public Statement
{
public:
  RootNode(StatementPtr tree);
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override; 

protected:
  void printC(std::ostream &os) const override;
};

#endif
