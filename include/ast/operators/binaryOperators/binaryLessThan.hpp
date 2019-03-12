#ifndef binaryLessThan_hpp
#define binaryLessThan_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryLessThan : public BinaryOperator
{ 
    using BinaryOperator::BinaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 