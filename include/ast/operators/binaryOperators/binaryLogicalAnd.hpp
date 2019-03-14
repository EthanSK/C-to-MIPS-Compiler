#ifndef binaryLogicalAnd_hpp
#define binaryLogicalAnd_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryLogicalAnd : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 