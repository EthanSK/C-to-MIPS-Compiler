#ifndef unaryMinus_hpp
#define unaryMinus_hpp

#include "unaryOperator.hpp"

class UnaryMinus : UnaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
