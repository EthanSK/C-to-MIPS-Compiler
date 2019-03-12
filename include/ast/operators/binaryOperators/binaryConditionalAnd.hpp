#ifndef binaryConditionalAnd_hpp
#define binaryConditionalAnd_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryConditionalAnd : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 