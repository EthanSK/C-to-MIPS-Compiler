#ifndef unaryNot_hpp
#define unaryNot_hpp

#include "unaryOperator.hpp"

class UnaryNot : public UnaryOperator
{ 
    using UnaryOperator::UnaryOperator;
    void printC(std::ostream &os) const override;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
}; 
     
#endif 
