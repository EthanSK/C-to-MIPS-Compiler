#ifndef binaryConditionalOr_hpp
#define binaryConditionalOr_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryConditionalOr : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 