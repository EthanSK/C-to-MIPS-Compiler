#ifndef binarySubtract_hpp
#define binarySubtract_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinarySubtract : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 