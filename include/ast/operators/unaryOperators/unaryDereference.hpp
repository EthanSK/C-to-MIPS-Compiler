#ifndef unaryDereference_hpp
#define unaryDereference_hpp

#include "unaryOperator.hpp"

class UnaryDereference : UnaryOperator
{ 
    void printCode(std::ostream &os) const override;
}; 
     
#endif 