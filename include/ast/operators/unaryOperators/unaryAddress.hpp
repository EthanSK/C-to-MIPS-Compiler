#ifndef unaryAddress_hpp
#define unaryAddress_hpp

#include "unaryOperator.hpp"

class UnaryAddress : public UnaryOperator
{ 
    using UnaryOperator::UnaryOperator;
    void printC(std::ostream &os) const override;
    int evalConst() const override;
    bool isConstant() const override;
}; 
     
#endif 
