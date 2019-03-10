#ifndef binaryGreaterThanOrEqualTo_hpp
#define binaryGreaterThanOrEqualTo_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryGreaterThanOrEqualTo : public BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 