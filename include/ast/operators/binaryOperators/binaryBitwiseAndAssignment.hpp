#ifndef binaryBitwiseAndAssignment_hpp
#define binaryBitwiseAndAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseAndAssignment : public BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 