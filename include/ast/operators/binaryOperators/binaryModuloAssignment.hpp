#ifndef binaryModuloAssignment_hpp
#define binaryModuloAssignment_hpp


#include <iostream>
#include "binaryOperator.hpp"
#include "context.hpp"

class BinaryModuloAssignment : public BinaryOperator
{ 
public:
    using BinaryOperator::BinaryOperator;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const override; 

protected:
    void printC(std::ostream &os) const override;
}; 
     
#endif 