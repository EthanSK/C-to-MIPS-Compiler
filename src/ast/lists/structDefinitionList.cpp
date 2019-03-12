#include "structDefinitionList.hpp"

void StructDefinitionList::printC(std::ostream &os) const
{
    std::vector<StatementPtr> elements = getVariables();
	os << "{";
    for(size_t i = 0; i < elements.size(); i++)
    {
        os << elements[i] << ";";
    }
    os << "}";
}