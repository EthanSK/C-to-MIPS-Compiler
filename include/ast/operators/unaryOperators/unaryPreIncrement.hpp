#ifndef unaryPreIncrement_hpp
#define unaryPreIncrement_hpp

#include "unaryOperator.hpp"

class UnaryPreIncrement : public UnaryOperator
{ 
    using UnaryOperator::UnaryOperator;
    void printC(std::ostream &os) const override;
    void generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const override;
}; 
     
#endif 
