#ifndef unaryDereference_hpp
#define unaryDereference_hpp

#include "unaryOperator.hpp"

class UnaryDereference : public UnaryOperator
{ 
    using UnaryOperator::UnaryOperator;
    void printC(std::ostream &os) const override;
    void generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const override;
}; 
     
#endif 
