#ifndef unarySizeof_hpp
#define unarySizeof_hpp

#include "unaryOperator.hpp"

class UnarySizeof : UnaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 
