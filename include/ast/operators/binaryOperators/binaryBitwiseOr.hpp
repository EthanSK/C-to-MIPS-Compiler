#ifndef binaryBitwiseOr_hpp
#define binaryBitwiseOr_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseOr : public BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 