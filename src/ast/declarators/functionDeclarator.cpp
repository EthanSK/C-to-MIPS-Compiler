#include "functionDeclarator.hpp"
#include <sstream>

FunctionDeclarator::FunctionDeclarator(StatementPtr identifier, StatementPtr paramList)
{
    branches.push_back(identifier);
    branches.push_back(paramList);
}  

StatementPtr FunctionDeclarator::getIdentifier() const{
    return branches[0];
}

StatementPtr FunctionDeclarator::getParamList() const{
    return branches[1];
}

std::string FunctionDeclarator::getIdentifierName() const{
    return getIdentifier()->toString();
}

void FunctionDeclarator::printC(std::ostream &os) const
{
    os << getIdentifier() << "(" << getParamList() << ")";
} 

void FunctionDeclarator::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    getIdentifier()->generatePython(os, context, scopeDepth + 1);
    os << "(";
    getParamList()->generatePython(os, context, scopeDepth + 1);
    os << ")";
}

void FunctionDeclarator::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    Instr instr("fdef", getIdentifierName());
    instrs.push_back(instr);
}