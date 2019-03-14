#ifndef binaryLeftShiftAssignment_hpp
#define binaryLeftShiftAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryLeftShiftAssignment : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 