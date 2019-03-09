#ifndef unaryPostIncrement_hpp
#define unaryPostIncrement_hpp

#include "unaryOperator.hpp"

class UnaryPostIncrement : UnaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 
