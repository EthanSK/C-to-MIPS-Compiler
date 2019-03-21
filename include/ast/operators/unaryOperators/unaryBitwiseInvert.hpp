#ifndef unaryBitwiseInvert_hpp
#define unaryBitwiseInvert_hpp

#include "unaryOperator.hpp"

class UnaryBitwiseInvert : public UnaryOperator
{ 
    using UnaryOperator::UnaryOperator;
    void printC(std::ostream &os) const override;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const override;
}; 
     
#endif 
