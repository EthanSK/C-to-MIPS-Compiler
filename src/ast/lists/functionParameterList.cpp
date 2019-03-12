#include "functionParameterList.hpp"

void FunctionParameterList::printC(std::ostream &os) const
{
    std::vector<StatementPtr> elements = getVariables();
	os << "(";
    for(size_t i = 0; i < elements.size(); i++)
    {
        os << elements[i] << ((i == elements.size() - 1) ? "" : ", ");
    }
    os << ")";
}