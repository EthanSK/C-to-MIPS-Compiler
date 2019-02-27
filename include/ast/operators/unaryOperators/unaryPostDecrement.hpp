#ifndef unaryPostDecrement_hpp
#define unaryPostDecrement_hpp

#include "unaryOperator.hpp"

class UnaryPostDecrement : UnaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
