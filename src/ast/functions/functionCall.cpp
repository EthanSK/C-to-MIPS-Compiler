#include "functionCall.hpp"

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
    os << getName() << getParameters();
} 

void FunctionCall::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    getName()->generatePython(os, context, scopeDepth);
    getParameters()->generatePython(os, context, scopeDepth);
}