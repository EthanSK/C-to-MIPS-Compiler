#ifndef unaryMinus_hpp
#define unaryMinus_hpp

#include "unaryOperator.hpp"

class UnaryMinus : UnaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 
