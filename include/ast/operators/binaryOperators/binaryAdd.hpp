#ifndef binaryAdd_hpp
#define binaryAdd_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryAddOperator : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
