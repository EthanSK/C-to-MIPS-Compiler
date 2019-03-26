#include "functionDeclarator.hpp"
#include "parameterList.hpp"
#include "declaration.hpp"
#include "utils.hpp"
#include <sstream>

FunctionDeclarator::FunctionDeclarator(StatementPtr identifier, StatementPtr paramList)
{
    branches.push_back(identifier);
    branches.push_back(paramList);
}  

StatementPtr FunctionDeclarator::getIdentifier() const{
    return branches[0];
}

StatementPtr FunctionDeclarator::getParamList() const{
    return branches[1];
}

std::string FunctionDeclarator::getIdentifierName() const{
    return getIdentifier()->toString();
}

void FunctionDeclarator::printC(std::ostream &os) const
{
    os << getIdentifier() << "(" << getParamList() << ")";
} 

void FunctionDeclarator::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    getIdentifier()->generatePython(os, context, scopeDepth + 1);
    os << "(";
    getParamList()->generatePython(os, context, scopeDepth + 1);
    os << ")";
}

void FunctionDeclarator::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    if (context.isFuncSymbolDefined(getIdentifierName()))
    {
        Instr instr("fdef", getIdentifierName());

        ParameterListPtr paramList = Utils::tryCast<ParameterList>(getParamList(), "parameter list of a function declarator must be of type parameterList");
        std::vector<StatementPtr> params = paramList->getNodes();

        for (size_t i = 0; i < params.size(); ++i)
        {
            DeclarationPtr declaration = Utils::tryCast<Declaration>(params[i], "param in function definition must be a valid declaration");
            DeclaratorListPtr declList = declaration->getDeclList();
            for (size_t j = 0; j < declList->getDeclCount(); ++j)
            {
                DeclaratorPtr decl = declList->getDeclarator(j);
                instr.extraData.push_back(decl->getIdentifierName());
                instr.extraData.push_back("4");
            }
        }

        instrs.push_back(instr);
    }
}