#ifndef binaryModuloAssignment_hpp
#define binaryModuloAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryModuloAssignment : public BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 