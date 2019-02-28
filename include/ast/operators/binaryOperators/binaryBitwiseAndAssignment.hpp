#ifndef binaryBitwiseAndAssignment_hpp
#define binaryBitwiseAndAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseAndAssignment : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 