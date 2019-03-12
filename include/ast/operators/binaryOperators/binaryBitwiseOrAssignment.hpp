#ifndef binaryBitwiseOrAssignment_hpp
#define binaryBitwiseOrAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseOrAssignment : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 