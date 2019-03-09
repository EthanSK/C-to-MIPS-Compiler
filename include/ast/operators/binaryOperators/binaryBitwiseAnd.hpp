#ifndef binaryBitwiseAnd_hpp
#define binaryBitwiseAnd_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryBitwiseAnd : BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 