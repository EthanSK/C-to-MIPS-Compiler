#ifndef returnKeyword_hpp
#define returnKeyword_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class ReturnKeyword : public Statement
{
public:
  ReturnKeyword(StatementPtr returnValue);

protected:
  StatementPtr getReturnValue() const;
  virtual void printC(std::ostream &os) const = 0;
};

#endif
