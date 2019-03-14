#ifndef continueKeyword_hpp
#define continueKeyword_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class ContinueKeyword : public Statement 
{
    //has no braches and carries no data
  protected:
    virtual void printC(std::ostream &os) const = 0;
};

#endif
