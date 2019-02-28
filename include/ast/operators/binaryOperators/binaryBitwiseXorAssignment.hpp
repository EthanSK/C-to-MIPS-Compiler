#ifndef binaryBitwiseXorAssignment_hpp
#define binaryBitwiseXorAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseXorAssignment : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 