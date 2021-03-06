#ifndef binaryGreaterThanOrEqualTo_hpp
#define binaryGreaterThanOrEqualTo_hpp


#include <iostream>
#include "binaryOperator.hpp"
#include "context.hpp"

class BinaryGreaterThanOrEqualTo : public BinaryOperator
{ 
public:
    using BinaryOperator::BinaryOperator;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
    virtual int evalConst() const override; 

protected:
    void printC(std::ostream &os) const override;
}; 
     
#endif 