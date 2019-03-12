#include "functionCall.hpp"

FunctionCall::FunctionCall(StatementPtr parameters){
    branches[0] = parameters;
}
StatementPtr FunctionCall::getParameters() const{
    return branches[0];
}
void FunctionCall::printC(std::ostream &os) const
{
    os << name << getParameters();
} 