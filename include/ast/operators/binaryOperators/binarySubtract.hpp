#ifndef binarySubtract_hpp
#define binarySubtract_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinarySubtract : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 