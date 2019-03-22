#include "initDeclarator.hpp"
#include "utils.hpp"

InitDeclarator::InitDeclarator(StatementPtr declarator, StatementPtr initializer)
{
    branches.push_back(declarator);
    branches.push_back(initializer);
}
  
DeclaratorPtr InitDeclarator::getDeclarator() const
{
    return Utils::tryCast<Declarator>(branches[0], "inner child of an init declarator must be a declarator");
}

StatementPtr InitDeclarator::getInitializer() const
{
    return branches[1];
}
  
std::string InitDeclarator::getIdentifierName() const
{
    return getDeclarator()->getIdentifierName();
}

void InitDeclarator::printC(std::ostream &os) const
{
    os << getDeclarator() << " = " << getInitializer();
}

void InitDeclarator::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    getDeclarator()->generatePython(os, context, scopeDepth);
    os << " = ";
    getInitializer()->generatePython(os, context, scopeDepth);
}

void InitDeclarator::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    std::string initName = context.makeName("init");
    getDeclarator()->generateIL(instrs, context, destReg);
    getInitializer()->generateIL(instrs, context, initName);
    instrs.push_back(ILinstr("mov", getDeclarator()->getIdentifierName(), initName));
}