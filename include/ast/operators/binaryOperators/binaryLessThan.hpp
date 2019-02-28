#ifndef binaryLessThan_hpp
#define binaryLessThan_hpp


#include <iostream>
#include "binaryOperator.hpp"

class BinaryLessThan : BinaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 