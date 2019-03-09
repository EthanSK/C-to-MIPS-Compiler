#ifndef unarySizeof_hpp
#define unarySizeof_hpp

#include "unaryOperator.hpp"

class UnarySizeof : UnaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
