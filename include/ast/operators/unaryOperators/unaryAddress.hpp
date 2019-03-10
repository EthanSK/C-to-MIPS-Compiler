#ifndef unaryAddress_hpp
#define unaryAddress_hpp

#include "unaryOperator.hpp"

class UnaryAddress : public UnaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 
