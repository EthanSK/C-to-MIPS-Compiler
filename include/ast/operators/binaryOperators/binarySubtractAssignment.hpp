#ifndef binarySubtractAssignment_hpp
#define binarySubtractAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinarySubtractAssignment : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 