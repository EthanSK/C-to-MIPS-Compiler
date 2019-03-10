#ifndef unaryNot_hpp
#define unaryNot_hpp

#include "unaryOperator.hpp"

class UnaryNot : public UnaryOperator
{ 
    void printC(std::ostream &os) const override;
}; 
     
#endif 
