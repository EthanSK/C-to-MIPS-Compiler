#ifndef binaryIsEqualTo_hpp
#define binaryIsEqualTo_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryIsEqualTo : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 