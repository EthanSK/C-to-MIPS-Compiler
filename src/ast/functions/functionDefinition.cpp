#include "functionDefinition.hpp"
#include "variableDeclaration.hpp"

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
    getDecl()->generatePython(os, context, scopeDepth);
    os << ":";
    context.dumpGlobals(os, scopeDepth + 1);
    getScopeBlock()->generatePython(os, context, scopeDepth + 1);
    context.indentStream(os, scopeDepth);
}