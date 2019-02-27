#ifndef unaryAddress_hpp
#define unaryAddress_hpp

#include "unaryOperator.hpp"

class UnaryAddress : UnaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
