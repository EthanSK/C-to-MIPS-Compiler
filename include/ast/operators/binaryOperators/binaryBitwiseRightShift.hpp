#ifndef binaryBitwiseRightShift_hpp
#define binaryBitwiseRightShift_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseRightShift : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 