#ifndef binaryAdd_hpp
#define binaryAdd_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryAdd : public BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 