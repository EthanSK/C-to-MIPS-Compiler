#ifndef unaryPreDecrement_hpp
#define unaryPreDecrement_hpp

#include "unaryOperator.hpp"

class UnaryPreDecrement : UnaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
