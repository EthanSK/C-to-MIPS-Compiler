#ifndef binaryGreaterThan_hpp
#define binaryGreaterThan_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryGreaterThan : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 