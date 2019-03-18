#include "variableInitialization.hpp"
#include <sstream>

VariableInitialization::VariableInitialization(StatementPtr identifier, StatementPtr initializer)
{
    branches.push_back(identifier);
    branches.push_back(initializer);
}

StatementPtr VariableInitialization::getIdentifier() const
{
    return branches[0];
}

StatementPtr VariableInitialization::getInitializer() const
{
    return branches[1];
}

void VariableInitialization::printC(std::ostream &os) const
{
    os << getIdentifier() << " = " << getInitializer();
}

void VariableInitialization::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    if (scopeDepth == 0)
    {
        std::stringstream str;
        str << getIdentifier();
        context.registerGlobal(str.str());
    }
    getIdentifier()->generatePython(os, context, scopeDepth);
    os << " = ";
    getInitializer()->generatePython(os, context, scopeDepth);
}