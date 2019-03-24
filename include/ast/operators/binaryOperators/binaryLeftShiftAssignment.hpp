#ifndef binaryLeftShiftAssignment_hpp
#define binaryLeftShiftAssignment_hpp


#include <iostream>
#include "binaryAssignmentOperator.hpp"
#include "context.hpp"

class BinaryLeftShiftAssignment : public BinaryAssignmentOperator
{ 
public:
    using BinaryAssignmentOperator::BinaryAssignmentOperator;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override; 

protected:
    void printC(std::ostream &os) const override;
}; 
     
#endif 