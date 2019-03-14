#ifndef unaryDereference_hpp
#define unaryDereference_hpp

#include "unaryOperator.hpp"

class UnaryDereference : public UnaryOperator
{ 
    using UnaryOperator::UnaryOperator;
    void printC(std::ostream &os) const override;
}; 
     
#endif 
