#ifndef unaryPreIncrement_hpp
#define unaryPreIncrement_hpp

#include "unaryOperator.hpp"

class UnaryPreIncrement : UnaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
