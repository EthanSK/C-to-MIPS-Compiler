#ifndef binaryBitwiseRightShiftAssignment_hpp
#define binaryBitwiseRightShiftAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseRightShiftAssignment : BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 