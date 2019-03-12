#ifndef binaryMultiply_hpp
#define binaryMultiply_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryMultiply : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 