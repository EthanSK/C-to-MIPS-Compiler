#ifndef unaryAdd_hpp
#define unaryAdd_hpp

#include "unaryOperator.hpp"

class UnaryAdd : public UnaryOperator
{ 
    using UnaryOperator::UnaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 
