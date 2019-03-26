#include "functionDefinition.hpp"
#include "declaration.hpp"
#include "utils.hpp"

FunctionDefinition::FunctionDefinition(StatementPtr decl, StatementPtr scopeBlock)
{
    branches.push_back(decl);
    branches.push_back(scopeBlock);
}

StatementPtr FunctionDefinition::getDecl() const
{
    return branches[0];
}

StatementPtr FunctionDefinition::getScopeBlock() const
{
    return branches[1];
}

void FunctionDefinition::printC(std::ostream &os) const
{
    os << std::endl << getDecl() << getScopeBlock();
}

void FunctionDefinition::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << "def ";
    getDecl()->generatePython(os, context, scopeDepth);
    os << ":";
    context.dumpGlobals(os, scopeDepth + 1);
    getScopeBlock()->generatePython(os, context, scopeDepth + 1);
    context.indentStream(os, scopeDepth);
}

void FunctionDefinition::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    DeclarationPtr declaration = Utils::tryCast<Declaration>(getDecl(), "function must contain a declaration");
    DeclaratorListPtr declList = declaration->getDeclList();
    if (declList->getDeclCount() == 0) { throw "cannot have a function declaration with no declarators"; }
    for (size_t i = 0; i < declList->getDeclCount(); ++i)
    {
        DeclaratorPtr decl = declList->getDeclarator(i);
        context.registerFuncSymbol(decl->getIdentifierName());
    }

    getDecl()->generateIL(instrs, context, destReg);
    getScopeBlock()->generateIL(instrs, context, destReg);
    instrs.push_back(Instr("fend"));
}