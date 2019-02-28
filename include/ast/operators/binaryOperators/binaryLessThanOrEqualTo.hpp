#ifndef binaryLessThanOrEqualTo_hpp
#define binaryLessThanOrEqualTo_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryLessThanOrEqualTo : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 