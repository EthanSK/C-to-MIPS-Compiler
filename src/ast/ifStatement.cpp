#include "ifStatement.hpp"

void IfStatement::printCode(std::ostream &os) const
{
    os << "if (" << branches[0] << ")" << branches[1] << "else" << branches[2]; //the scopeBlock printCode is repsonsible for printing the { } with new lines
}