#include "functionCall.hpp"

FunctionCall::FunctionCall(std::string _name, StatementPtr parameters) : Function(_name) {
    branches[0] = parameters;
}  
StatementPtr FunctionCall::getParameters() const{
    return branches[0];
}
void FunctionCall::printC(std::ostream &os) const
{
    os << name << getParameters();
} 