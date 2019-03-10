#ifndef unaryPreIncrement_hpp
#define unaryPreIncrement_hpp

#include "unaryOperator.hpp"

class UnaryPreIncrement : public UnaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 
