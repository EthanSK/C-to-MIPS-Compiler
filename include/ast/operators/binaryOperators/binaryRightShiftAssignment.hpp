#ifndef binaryRightShiftAssignment_hpp
#define binaryRightShiftAssignment_hpp


#include <iostream>
#include "binaryAssignmentOperator.hpp"
#include "context.hpp"

class BinaryRightShiftAssignment : public BinaryAssignmentOperator
{ 
public:
    using BinaryAssignmentOperator::BinaryAssignmentOperator;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override; 

protected:
    void printC(std::ostream &os) const override;
}; 
     
#endif 