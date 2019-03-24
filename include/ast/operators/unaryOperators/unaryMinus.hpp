#ifndef unaryMinus_hpp
#define unaryMinus_hpp

#include "unaryOperator.hpp"

class UnaryMinus : public UnaryOperator
{ 
    using UnaryOperator::UnaryOperator;
    void printC(std::ostream &os) const override;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
    int evalConst() const override;
}; 
     
#endif 
