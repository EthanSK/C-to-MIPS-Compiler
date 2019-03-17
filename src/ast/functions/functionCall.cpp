#include "functionCall.hpp"

FunctionCall::FunctionCall(std::string name, StatementPtr parameters) : _name(name) {
    branches.push_back(parameters);
}  
StatementPtr FunctionCall::getParameters() const{
    return branches[0];
}
void FunctionCall::printC(std::ostream &os) const
{
    os << _name << getParameters();
} 

void FunctionCall::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << _name;
    getParameters()->generatePython(os, context, scopeDepth);
}