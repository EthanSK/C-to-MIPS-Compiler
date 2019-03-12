#ifndef binaryMultiplyAssignment_hpp
#define binaryMultiplyAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryMultiplyAssignment : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 