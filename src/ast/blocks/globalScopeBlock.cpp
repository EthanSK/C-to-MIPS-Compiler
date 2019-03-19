#include "globalScopeBlock.hpp"

void GlobalScopeBlock::printC(std::ostream &os) const
{
    os << "\n";
    for(size_t i = 0; i < branches.size(); i++)
    {
        os << branches[i] << "\n";
    }
    os << std::flush;
}

void GlobalScopeBlock::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    for(size_t i = 0; i < branches.size(); i++)
    {
        context.indentStream(os, scopeDepth);
        branches[i]->generatePython(os, context, scopeDepth);
    }
    os << std::flush;
}