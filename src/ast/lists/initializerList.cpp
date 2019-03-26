#include "initializerList.hpp"
#include "utils.hpp"
#include "rvalue.hpp"

InitializerList::InitializerList(std::vector<StatementPtr> elements){
    branches = elements;
}

std::vector<StatementPtr> InitializerList::getElements() const {
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

bool InitializerList::isConstant() const
{
    for (size_t i = 0; i < branches.size(); ++i)
    {
        RValuePtr rvalue = Utils::tryCast<RValue>(branches[i], "initializer list may only contain rvalues");
        if (!rvalue->isConstant()) { return false; }
    }

    return true;
}