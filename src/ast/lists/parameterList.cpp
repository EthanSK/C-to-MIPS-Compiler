#include "parameterList.hpp"

void ParameterList::printC(std::ostream &os) const
{
    std::vector<StatementPtr> initializations = getNodes();
    for (size_t i = 0; i < initializations.size(); ++i)
    {
        if (i > 0) { os << ", "; }
        os << initializations[i];
    }
}

void ParameterList::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    std::vector<StatementPtr> initializations = getNodes();
    for (size_t i = 0; i < initializations.size(); ++i)
    {
        if (i > 0) { os << ", "; }
        initializations[i]->generatePython(os, context, scopeDepth);
    }
}

void ParameterList::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    for (size_t i = 0; i < branches.size(); ++i)
    {
        branches[i]->generateIL(instrs, context, destReg);
    }
}
