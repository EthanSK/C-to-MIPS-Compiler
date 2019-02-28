#ifndef binaryBitwiseLeftShiftAssignment_hpp
#define binaryBitwiseLeftShiftAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseLeftShiftAssignment : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 