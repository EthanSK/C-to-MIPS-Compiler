#ifndef unaryPostDecrement_hpp
#define unaryPostDecrement_hpp

#include "unaryOperator.hpp"

class UnaryPostDecrement : UnaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 
