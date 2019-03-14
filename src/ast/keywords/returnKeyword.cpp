#include "returnKeyword.hpp"

ReturnKeyword::ReturnKeyword(StatementPtr returnValue){
    branches.push_back(returnValue); 
}
StatementPtr ReturnKeyword::getReturnValue() const
{
    return branches[0];
}

void ReturnKeyword::printC(std::ostream &os) const
{
    os << "return " << getReturnValue();
}