#ifndef binaryIsEqualTo_hpp
#define binaryIsEqualTo_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryIsEqualTo : public BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 