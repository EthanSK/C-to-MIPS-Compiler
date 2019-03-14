#ifndef scopeBlock_hpp
#define scopeBlock_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class ScopeBlock : public Statement //aka compound statement, used to represent content between curly braces everywhere eg loops, conditions, pure scope, etc...
{
public:
  ScopeBlock(std::vector<StatementPtr> branches);
  void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
  void printC(std::ostream &os) const override;
};

#endif
