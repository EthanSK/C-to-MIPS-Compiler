#include "returnKeyword.hpp"

ReturnKeyword::ReturnKeyword(StatementPtr returnValue){
    branches.push_back(returnValue); 
}
StatementPtr ReturnKeyword::getReturnValue() const
{
    return branches[0];
}

void ReturnKeyword::printC(std::ostream &os) const
{
    os << "return " << getReturnValue();
}

void ReturnKeyword::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << "return ";
    getReturnValue()->generatePython(os, context, scopeDepth);
}

void ReturnKeyword::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    getReturnValue()->generateIL(instrs, context, "$t0");
    instrs.push_back(Instr("retv", "$t0"));
} 