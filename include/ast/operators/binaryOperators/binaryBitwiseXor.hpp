#ifndef binaryBitwiseXor_hpp
#define binaryBitwiseXor_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseXor : public BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 