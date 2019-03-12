#include "functionDeclaration.hpp"

StatementPtr FunctionDeclaration::getParameters() const{
    return branches[0];
}
void FunctionDeclaration::printC(std::ostream &os) const
{
    os << name << getParameters();
} 