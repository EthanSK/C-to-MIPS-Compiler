#ifndef unaryPreDecrement_hpp
#define unaryPreDecrement_hpp

#include "unaryOperator.hpp"

class UnaryPreDecrement : public UnaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 
