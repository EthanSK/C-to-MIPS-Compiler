#ifndef binaryInNotEqualTo_hpp
#define binaryInNotEqualTo_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryInNotEqualTo : BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 