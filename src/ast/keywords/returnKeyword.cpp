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

void ReturnKeyword::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    std::string retReg = context.makeName("ret");
    getReturnValue()->generateIL(instrs, context, retReg);
    instrs.push_back(ILinstr("retv", retReg));
} 