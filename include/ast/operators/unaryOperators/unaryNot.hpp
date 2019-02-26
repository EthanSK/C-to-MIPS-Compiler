#ifndef unaryNot_hpp
#define unaryNot_hpp

#include "unaryOperator.hpp"

class UnaryNot : UnaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 
