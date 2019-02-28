#ifndef binarySubtractionAssignment_hpp
#define binarySubtractionAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinarySubtractionAssignment : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 