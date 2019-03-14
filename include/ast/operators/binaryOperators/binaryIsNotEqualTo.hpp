#ifndef binaryIsNotEqualTo_hpp
#define binaryIsNotEqualTo_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryIsNotEqualTo : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 