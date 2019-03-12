#include "functionCall.hpp"

StatementPtr FunctionCall::getParameters() const{
    return branches[0];
}
void FunctionCall::printC(std::ostream &os) const
{
    os << name << getParameters();
} 