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
  SequenceBlock(std::vector<StatementPtr> branches);
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
  void printC(std::ostream &os) const override;
};

#endif
