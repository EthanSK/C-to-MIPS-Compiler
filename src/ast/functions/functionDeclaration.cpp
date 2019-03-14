#include "functionDeclaration.hpp"
#include "variableDeclaration.hpp"

FunctionDeclaration::FunctionDeclaration(StatementPtr type, std::string name, StatementPtr parameters) : _name(name)
{
    branches.push_back(type);
    branches.push_back(parameters);
}

StatementPtr FunctionDeclaration::getType() const
{
    return branches[0];
}

StatementPtr FunctionDeclaration::getParameters() const
{
    return branches[1];
}

void FunctionDeclaration::printC(std::ostream &os) const
{
    os << getType() << " " << _name << getParameters();
}