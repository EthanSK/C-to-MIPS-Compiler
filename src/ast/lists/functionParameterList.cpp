#include "functionParameterList.hpp"

void FunctionParameterList::printC(std::ostream &os) const
{
	os << "(";
    for(size_t i = 0; i < getVariableDeclarations().size(); i++)
    {
        os << getVariableDeclarations()[i] << ((i == getVariableDeclarations().size() - 1) ? "" : ", ");
    }
    os << ")";
} 