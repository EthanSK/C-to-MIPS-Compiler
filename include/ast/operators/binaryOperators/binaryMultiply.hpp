#ifndef binaryMultiply_hpp
#define binaryMultiply_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryMultiply : BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 