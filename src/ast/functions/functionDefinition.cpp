#include "functionDefinition.hpp"

FunctionDefinition::FunctionDefinition(StatementPtr decl, StatementPtr scopeBlock)
{
    branches.push_back(decl);
    branches.push_back(scopeBlock);
}

StatementPtr FunctionDefinition::getDecl() const
{
    return branches[0];
}

StatementPtr FunctionDefinition::getScopeBlock() const
{
    return branches[1];
}

void FunctionDefinition::printC(std::ostream &os) const
{
    os << std::endl << getDecl() << getScopeBlock();
}

void FunctionDefinition::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << "def ";
    getDecl()->generatePython(os, context, scopeDepth);
    os << ":";
    context.dumpGlobals(os, scopeDepth + 1);
    getScopeBlock()->generatePython(os, context, scopeDepth + 1);
    context.indentStream(os, scopeDepth);
}

void FunctionDefinition::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    getDecl()->generateIL(instrs, context, destReg);
    getScopeBlock()->generateIL(instrs, context, destReg);
    instrs.push_back(ILinstr("fend", ""));
}