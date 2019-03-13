#ifndef binaryLeftShift_hpp
#define binaryLeftShift_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryLeftShift : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 