#ifndef binaryGreaterThan_hpp
#define binaryGreaterThan_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryGreaterThan : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 