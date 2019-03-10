#ifndef unaryMinus_hpp
#define unaryMinus_hpp

#include "unaryOperator.hpp"

class UnaryMinus : public UnaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 
