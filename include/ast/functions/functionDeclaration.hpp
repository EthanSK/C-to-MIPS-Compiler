#ifndef functionDeclaration_hpp
#define functionDeclaration_hpp

#include <iostream>
#include "statement.hpp"

class FunctionDeclaration : public Statement 
{
  public:
    float getValue() const;
    void printC(std::ostream &os) const override;
};

#endif