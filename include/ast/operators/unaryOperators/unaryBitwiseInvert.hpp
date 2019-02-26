#ifndef unaryBitwiseInvert_hpp
#define unaryBitwiseInvert_hpp

#include "unaryOperator.hpp"

class unaryBitwiseInvert : UnaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
