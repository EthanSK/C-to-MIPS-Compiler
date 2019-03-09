#ifndef binaryModulo_hpp
#define binaryModulo_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryModulo : BinaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 