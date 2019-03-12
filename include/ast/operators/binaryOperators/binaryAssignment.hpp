#ifndef binaryAssignment_hpp
#define binaryAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryAssignment : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 