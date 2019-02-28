#ifndef binaryConditionalAnd_hpp
#define binaryConditionalAnd_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryConditionalAnd : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 