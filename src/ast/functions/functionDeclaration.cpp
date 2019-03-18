#include "functionDeclaration.hpp"
#include "variableDeclaration.hpp"

FunctionDeclaration::FunctionDeclaration(StatementPtr type, StatementPtr name, StatementPtr parameters)
{
    branches.push_back(type);
    branches.push_back(name);
    branches.push_back(parameters);
}

StatementPtr FunctionDeclaration::getType() const
{
    return branches[0];
}

StatementPtr FunctionDeclaration::getName() const
{
    return branches[1];
}

StatementPtr FunctionDeclaration::getParameters() const
{
    return branches[2];
}

void FunctionDeclaration::printC(std::ostream &os) const
{
    os << getType() << " " << getName() << getParameters();
}