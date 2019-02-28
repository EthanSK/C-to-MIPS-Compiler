#ifndef binaryModuloAssignment_hpp
#define binaryModuloAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryModuloAssignment : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 