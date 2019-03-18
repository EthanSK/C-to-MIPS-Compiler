#include "expressionList.hpp"

void ExpressionList::printC(std::ostream &os) const
{
    std::vector<StatementPtr> initializations = getNodes();
    for (int i = 0; i < initializations.size(); ++i)
    {
        if (i > 0) { os << ", "; }
        os << initializations[i];
    }
}

void ExpressionList::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    std::vector<StatementPtr> initializations = getNodes();
    for (int i = 0; i < initializations.size(); ++i)
    {
        if (i > 0) { os << ", "; }
        initializations[i]->generatePython(os, context, scopeDepth);
    }
}