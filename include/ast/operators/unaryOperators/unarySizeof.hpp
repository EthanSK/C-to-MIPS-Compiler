#ifndef unarySizeof_hpp
#define unarySizeof_hpp

#include "unaryOperator.hpp"

class UnarySizeof : public UnaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 
