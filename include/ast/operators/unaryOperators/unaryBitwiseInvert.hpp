#ifndef unaryBitwiseInvert_hpp
#define unaryBitwiseInvert_hpp

#include "unaryOperator.hpp"

class UnaryBitwiseInvert : public UnaryOperator
{ 
    using UnaryOperator::UnaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 
