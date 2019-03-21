#include "directDeclarator.hpp"
#include <sstream>

DirectDeclarator::DirectDeclarator(StatementPtr identifier)
{
    branches.push_back(identifier);
}  

StatementPtr DirectDeclarator::getIdentifier() const{
    return branches[0];
}

std::string DirectDeclarator::getIdentifierName() const{
    return getIdentifier()->toString();
}

void DirectDeclarator::printC(std::ostream &os) const
{
    os << getIdentifier();
} 

void DirectDeclarator::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    if (scopeDepth == 0) { context.registerGlobal(getIdentifierName()); }
    getIdentifier()->generatePython(os, context, scopeDepth);
}

void DirectDeclarator::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    ILinstr instr("decl", getIdentifierName());
    instrs.push_back(instr);
}