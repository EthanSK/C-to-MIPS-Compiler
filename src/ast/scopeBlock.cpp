#include "scopeBlock.hpp"

ScopeBlock::ScopeBlock(std::vector<StatementPtr> branches){
    _branches = branches;
}
void ScopeBlock::printC(std::ostream &os) const
{
    os << "\n{\n";
    for(size_t i = 0; i < branches.size(); i++)
    {
        os << branches[i] << ";\n";
    }
    os << "}";
}