#ifndef binaryBitwiseLeftShift_hpp
#define binaryBitwiseLeftShift_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseLeftShift : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 