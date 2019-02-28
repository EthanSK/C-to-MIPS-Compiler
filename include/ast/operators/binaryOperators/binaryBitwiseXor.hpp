#ifndef binaryBitwiseXor_hpp
#define binaryBitwiseXor_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseXor : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 