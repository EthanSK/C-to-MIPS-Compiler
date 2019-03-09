#include "doWhileLoop.hpp"

void DoWhileLoop::printCode(std::ostream &os) const 
{
    os << "do" << branches[0] << "while ( " << branches[1] << ")";
}