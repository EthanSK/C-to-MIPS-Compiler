#include "scopeBlock.hpp"

void ScopeBlock::printCode(std::ostream &os) const
{
    for(size_t i = 0; i < branches.size(); i++)
    {
        std::cout << branches[i] << std::endl;
    }
}