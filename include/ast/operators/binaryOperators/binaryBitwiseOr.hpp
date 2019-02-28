#ifndef binaryBitwiseOr_hpp
#define binaryBitwiseOr_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseOr : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 