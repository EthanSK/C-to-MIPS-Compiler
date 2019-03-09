#include "whileLoop.hpp"

void WhileLoop::printC(std::ostream &os) const 
{
    os << "while (" << branches[0] << ")" << branches[1];
}