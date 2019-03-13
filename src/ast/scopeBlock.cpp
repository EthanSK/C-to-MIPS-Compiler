#include "scopeBlock.hpp"

ScopeBlock::ScopeBlock(std::vector<StatementPtr> _branches){
    branches = _branches;
}
void ScopeBlock::printC(std::ostream &os) const
{
    os << "\n{\n";
    for(size_t i = 0; i < branches.size(); i++)
    {
        os << branches[i] << ";\n";
    }
    os << "}" << std::endl; //to flush the buffer
}