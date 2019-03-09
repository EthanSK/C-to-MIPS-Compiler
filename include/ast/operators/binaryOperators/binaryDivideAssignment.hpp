#ifndef binaryDivideAssignment_hpp
#define binaryDivideAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryDivideAssignment : BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 