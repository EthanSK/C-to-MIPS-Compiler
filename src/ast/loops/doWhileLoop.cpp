#include "doWhileLoop.hpp"

void DoWhileLoop::printC(std::ostream &os) const 
{
    os << "do" << branches[0] << "while ( " << branches[1] << ")";
}