#include "variable.hpp"

void Variable::printC(std::ostream &os) const
{
    
    os << "if (" << branches[0] << ")" << branches[1] << "else" << branches[2]; //the scopeBlock printC is repsonsible for printing the { } with new lines
}