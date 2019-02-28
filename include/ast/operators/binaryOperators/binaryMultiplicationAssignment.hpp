#ifndef binaryMultiplicationAssignment_hpp
#define binaryMultiplicationAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryMultiplicationAssignment : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 