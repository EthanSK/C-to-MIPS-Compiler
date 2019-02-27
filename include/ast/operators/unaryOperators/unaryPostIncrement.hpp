#ifndef unaryPostIncrement_hpp
#define unaryPostIncrement_hpp

#include "unaryOperator.hpp"

class UnaryPostIncrement : UnaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
