#ifndef binaryBitwiseOrAssignment_hpp
#define binaryBitwiseOrAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseOrAssignment : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 