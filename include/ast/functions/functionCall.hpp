#ifndef functionCall_hpp
#define functionCall_hpp

#include <iostream>
#include "literal.hpp"

class FunctionCall : public 
{
  public:
    float getValue() const;
    void printC(std::ostream &os) const override;
};

#endif