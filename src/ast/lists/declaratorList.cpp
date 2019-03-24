#include "declaratorList.hpp"
#include "utils.hpp"

void DeclaratorList::printC(std::ostream &os) const
{
    std::vector<StatementPtr> initializations = getNodes();
    for (int i = 0; i < initializations.size(); ++i)
    {
        if (i > 0) { os << ", "; }
        os << initializations[i];
    }
}

DeclaratorPtr DeclaratorList::getDeclarator(int index) const
{
    return Utils::tryCast<Declarator>(branches[index], "decl list can only contain declarators");
}

int DeclaratorList::getDeclCount() const
{
    return branches.size();
}

void DeclaratorList::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    for (int i = 0; i < branches.size(); ++i)
    {
        DeclaratorPtr decl = getDeclarator(i);
        if (i > 0) { context.indentStream(os, scopeDepth); }
        decl->generatePython(os, context, scopeDepth);
        if (decl->declType() == Declarator::DeclTypeEnum::direct)
        {
            os << " = 0";
        }
    }
}

void DeclaratorList::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    for (int i = 0; i < branches.size(); ++i)
    {
        getDeclarator(i)->generateIL(instrs, context, destReg);
    }
}