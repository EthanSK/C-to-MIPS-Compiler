#ifndef binaryBitwiseXorAssignment_hpp
#define binaryBitwiseXorAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseXorAssignment : public BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 