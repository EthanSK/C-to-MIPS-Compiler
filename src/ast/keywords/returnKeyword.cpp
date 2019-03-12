#include "returnKeyword.hpp"

StatementPtr ReturnKeyword::getReturnValue() const
{
    return branches[0];
}

void ReturnKeyword::printC(std::ostream &os) const
{
    os << "return " << getReturnValue();
}