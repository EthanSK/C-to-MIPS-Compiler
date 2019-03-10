#ifndef binaryLessThanOrEqualTo_hpp
#define binaryLessThanOrEqualTo_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryLessThanOrEqualTo : public BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 