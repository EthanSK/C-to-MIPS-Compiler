#ifndef binaryDivide_hpp
#define binaryDivide_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryDivide : BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 