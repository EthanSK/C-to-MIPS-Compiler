#ifndef binaryConditionalOr_hpp
#define binaryConditionalOr_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryConditionalOr : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 