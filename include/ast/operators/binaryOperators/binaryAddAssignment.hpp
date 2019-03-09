#ifndef binaryAddAssignment_hpp
#define binaryAddAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryAddAssignment : BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 