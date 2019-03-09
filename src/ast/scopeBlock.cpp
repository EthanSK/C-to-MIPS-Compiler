#include "scopeBlock.hpp"

void ScopeBlock::printC(std::ostream &os) const
{
    os << "\n{\n";
    for(size_t i = 0; i < branches.size(); i++)
    {
        os << branches[i] << std::endl;
    }
    os << "\n}" << std::endl; //to flush the buffer
}