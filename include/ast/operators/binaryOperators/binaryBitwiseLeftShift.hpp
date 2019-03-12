#ifndef binaryBitwiseLeftShift_hpp
#define binaryBitwiseLeftShift_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseLeftShift : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 