#include "variableDeclaration.hpp"
#include "variableInitializationList.hpp"
#include "declarator.hpp"

VariableDeclaration::VariableDeclaration(StatementPtr type, StatementPtr initList)
{
    branches.push_back(type);
    branches.push_back(initList);
}

StatementPtr VariableDeclaration::getType() const
{
    return branches[0];
}

StatementPtr VariableDeclaration::getInitList() const
{
    return branches[1];
}

std::vector<StatementPtr> VariableDeclaration::getInitializations() const
{
    const VariableInitializationList* list = reinterpret_cast<const VariableInitializationList*>(getInitList());
    return list->getInitializations();
}

void VariableDeclaration::printC(std::ostream &os) const
{
    std::vector<StatementPtr> initializations = getInitializations();
    os << getType() << " ";
    for (int i = 0; i < initializations.size(); ++i)
    {
        if (i > 0) { os << ", "; }
        os << initializations[i];
    }
}

void VariableDeclaration::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    std::vector<StatementPtr> initializations = getInitializations();
    for (int i = 0; i < initializations.size(); ++i)
    {
        if (scopeDepth == 0)
        {
            DeclaratorPtr decl = reinterpret_cast<DeclaratorPtr>(initializations[i]);
            context.registerGlobal(decl->getIdentifierName());
        }

        if (i > 0) { context.indentStream(os, scopeDepth); }
        initializations[i]->generatePython(os, context, scopeDepth);
    }
}