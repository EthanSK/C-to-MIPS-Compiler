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
  void printC(std::ostream &os) const override;
};

#endif
