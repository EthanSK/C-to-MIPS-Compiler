#include "scopeBlock.hpp"

ScopeBlock::ScopeBlock(std::vector<StatementPtr> branches){
    this->branches = branches;
}

void ScopeBlock::printC(std::ostream &os) const
{
    os << "\n{\n";
    for(size_t i = 0; i < branches.size(); i++)
    {
        os << branches[i] << ";\n";
    }
    os << "}" << std::flush;
}

void ScopeBlock::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    for(size_t i = 0; i < branches.size(); i++)
    {
        branches[i]->generatePython(os, context, scopeDepth);
        os << "\n";
    }
    os <<std::flush;
}