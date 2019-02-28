#ifndef binaryBitwiseRightShiftAssignment_hpp
#define binaryBitwiseRightShiftAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseRightShiftAssignment : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 