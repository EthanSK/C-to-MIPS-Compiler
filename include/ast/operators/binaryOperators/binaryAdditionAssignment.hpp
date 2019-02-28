#ifndef binaryAdditionAssignment_hpp
#define binaryAdditionAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryAdditionAssignment : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 