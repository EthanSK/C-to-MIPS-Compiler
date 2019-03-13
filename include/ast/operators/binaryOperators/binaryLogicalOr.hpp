#ifndef binaryLogicalOr_hpp
#define binaryLogicalOr_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryLogicalOr : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 