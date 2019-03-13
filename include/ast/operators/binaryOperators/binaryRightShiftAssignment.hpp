#ifndef binaryRightShiftAssignment_hpp
#define binaryRightShiftAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryRightShiftAssignment : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 