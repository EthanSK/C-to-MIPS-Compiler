#ifndef scopeBlock_hpp
#define scopeBlock_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class ScopeBlock : public Statement //aka compound statement, used to represent content between curly braces everywhere eg loops, conditions, pure scope, etc...
{
  protected:
    void printC(std::ostream &os) const override;
};

#endif
