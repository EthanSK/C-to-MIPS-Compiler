#include "functionDefinition.hpp"
#include "variableDeclaration.hpp"

FunctionDefinition::FunctionDefinition(StatementPtr type, std::string name, StatementPtr parameters, StatementPtr scopeBlock) : _name(name)
{
    branches.push_back(type);
    branches.push_back(parameters);
    branches.push_back(scopeBlock);
}

StatementPtr FunctionDefinition::getType() const
{
    return branches[0];
}

StatementPtr FunctionDefinition::getParameters() const
{
    return branches[1];
}

StatementPtr FunctionDefinition::getScopeBlock() const
{
    return branches[2];
}

void FunctionDefinition::printC(std::ostream &os) const
{
    os << getType() << " " << _name << getParameters() << getScopeBlock();
}

void FunctionDefinition::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << "def " << _name;
    getParameters()->generatePython(os, context, scopeDepth);
    os << ":";
    getScopeBlock()->generatePython(os, context, scopeDepth + 1);
}