#ifndef unaryPostDecrement_hpp
#define unaryPostDecrement_hpp

#include "unaryOperator.hpp"

class UnaryPostDecrement : public UnaryOperator
{ 
    using UnaryOperator::UnaryOperator;
    void printC(std::ostream &os) const override;
    void generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const override;
}; 
     
#endif 
