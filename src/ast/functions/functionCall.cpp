#include "functionCall.hpp"
#include <sstream>

FunctionCall::FunctionCall(StatementPtr name, StatementPtr parameters) {
    branches.push_back(name);
    branches.push_back(parameters);
}  

StatementPtr FunctionCall::getName() const{
    return branches[0];
}

StatementPtr FunctionCall::getParameters() const{
    return branches[1];
}

void FunctionCall::printC(std::ostream &os) const
{
    os << getName() << "(" << getParameters() << ")";
} 

void FunctionCall::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    getName()->generatePython(os, context, scopeDepth);
    os << "(";
    getParameters()->generatePython(os, context, scopeDepth);
    os << ")";
}

void FunctionCall::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    Instr instr("fcall", destReg, getName()->toString());
    instrs.push_back(instr);
}