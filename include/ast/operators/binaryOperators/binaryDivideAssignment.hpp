#ifndef binaryDivideAssignment_hpp
#define binaryDivideAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryDivideAssignment : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 