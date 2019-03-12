#include "functionDefinition.hpp"

StatementPtr FunctionDefinition::getParameters() const{
    return branches[0]; 
}
StatementPtr FunctionDefinition::getScopeBlock() const{
    return branches[1];
}
void FunctionDefinition::printC(std::ostream &os) const
{
    os << name << getParameters();
} 