#include "forLoop.hpp"

void ForLoop::printC(std::ostream &os) const
{
    os << "for (" << branches[0] << "; " << branches[1] << "; " << branches[2] << " )" << branches[3];
}