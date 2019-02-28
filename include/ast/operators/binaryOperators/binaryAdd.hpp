#ifndef binaryAdd_hpp
#define binaryAdd_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryAdd : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 