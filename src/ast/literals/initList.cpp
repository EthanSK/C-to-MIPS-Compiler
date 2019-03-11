#include "initList.hpp"

void InitList::printC(std::ostream &os) const
{
	os << "{";
    for(size_t i = 0; i < branches.size(); i++)
    {
        os << branches[i] << ((i == branches.size() - 1) ? "" : ", ");
    }
    os << "}";
}