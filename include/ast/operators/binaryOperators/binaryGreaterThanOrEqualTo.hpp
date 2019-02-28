#ifndef binaryGreaterThanOrEqualTo_hpp
#define binaryGreaterThanOrEqualTo_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryGreaterThanOrEqualTo : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 