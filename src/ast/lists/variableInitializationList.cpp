#include "variableInitializationList.hpp"

VariableInitializationList::VariableInitializationList(std::vector<StatementPtr> initializations){
    branches = initializations; 
} 

std::vector<StatementPtr> VariableInitializationList::getInitializations() const {
    return branches;
} 

void VariableInitializationList::printC(std::ostream &os) const
{
    std::vector<StatementPtr> initializations = getInitializations();
    for (int i = 0; i < initializations.size(); ++i)
    {
        if (i > 0) { os << ", "; }
        os << initializations[i];
    }
}

void VariableInitializationList::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    std::vector<StatementPtr> initializations = getInitializations();
    for (int i = 0; i < initializations.size(); ++i)
    {
        if (i > 0) { os << "\n"; }
        initializations[i]->generatePython(os, context, scopeDepth);
    }
}
