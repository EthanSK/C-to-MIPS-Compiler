#ifndef binaryRightShift_hpp
#define binaryRightShift_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryRightShift : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 