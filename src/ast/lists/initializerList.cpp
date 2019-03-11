#include "initializerList.hpp"

std::vector<StatementPtr> getElements() const {
    return branches;
} 

void InitializerList::printC(std::ostream &os) const
{
    std::vector<StatementPtr> elements = getElements();
	os << "{";
    for(size_t i = 0; i < elements.size(); i++)
    {
        os << elements[i] << ((i == elements.size() - 1) ? "" : ", ");
    }
    os << "}";
}