#ifndef globalScopeBlock_hpp
#define globalScopeBlock_hpp

#include "sequenceBlock.hpp"

class GlobalScopeBlock : public SequenceBlock
{
public:
  using ScopeBlock::ScopeBlock;
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
  void printC(std::ostream &os) const override;
};

#endif
