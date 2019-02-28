#ifndef binaryDivisionAssignment_hpp
#define binaryDivisionAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryDivisionAssignment : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 