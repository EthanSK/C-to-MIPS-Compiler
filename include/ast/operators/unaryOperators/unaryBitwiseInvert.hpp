#ifndef unaryBitwiseInvert_hpp
#define unaryBitwiseInvert_hpp

#include "unaryOperator.hpp"

class UnaryBitwiseInvert : UnaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
