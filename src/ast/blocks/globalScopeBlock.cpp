#include "globalScopeBlock.hpp"

void GlobalScopeBlock::printC(std::ostream &os) const
{
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
        branches[i]->generatePython(os, context, scopeDepth);
        context.indentStream(os, scopeDepth);
    }
    os << std::flush;
}