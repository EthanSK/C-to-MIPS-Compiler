#include "whileLoop.hpp"

void WhileLoop::printCode(std::ostream &os) const 
{
    os << "while (" << branches[0] << ")" << branches[1];
}