#ifndef unaryPostIncrement_hpp
#define unaryPostIncrement_hpp

#include "unaryOperator.hpp"

class UnaryPostIncrement : public UnaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 
