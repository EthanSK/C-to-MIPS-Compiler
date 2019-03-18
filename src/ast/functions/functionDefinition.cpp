#include "functionDefinition.hpp"
#include "variableDeclaration.hpp"

FunctionDefinition::FunctionDefinition(StatementPtr type, StatementPtr name, StatementPtr parameters, StatementPtr scopeBlock)
{
    branches.push_back(type);
    branches.push_back(name);
    branches.push_back(parameters);
    branches.push_back(scopeBlock);
}

StatementPtr FunctionDefinition::getType() const
{
    return branches[0];
}

StatementPtr FunctionDefinition::getName() const
{
    return branches[1];
}

StatementPtr FunctionDefinition::getParameters() const
{
    return branches[2];
}

StatementPtr FunctionDefinition::getScopeBlock() const
{
    return branches[3];
}

void FunctionDefinition::printC(std::ostream &os) const
{
    os << std::endl << getType() << " " << getName() << getParameters() << getScopeBlock();
}

void FunctionDefinition::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << "def ";
    getName()->generatePython(os, context, scopeDepth + 1);
    getParameters()->generatePython(os, context, scopeDepth + 1);
    os << ":";
    context.dumpGlobals(os, scopeDepth + 1);
    getScopeBlock()->generatePython(os, context, scopeDepth + 1);
    context.indentStream(os, scopeDepth);
}