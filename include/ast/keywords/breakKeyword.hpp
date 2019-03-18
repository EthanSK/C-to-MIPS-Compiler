#ifndef breakKeyword_hpp
#define breakKeyword_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class BreakKeyword : public Statement
{
    //has no braches and carries no data
  protected:
    virtual void printC(std::ostream &os) const override;
};

#endif
