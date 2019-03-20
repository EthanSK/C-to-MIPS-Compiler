#ifndef functionDeclarator_hpp
#define functionDeclarator_hpp

#include "declarator.hpp"
#include "parameterList.hpp"

class FunctionDeclarator : public Declarator
{
public:
    FunctionDeclarator(StatementPtr identifier, StatementPtr paramList);
    FunctionDeclarator(StatementPtr identifier, std::vector<StatementPtr> paramList) : FunctionDeclarator(identifier, new ParameterList(paramList)) { }
    FunctionDeclarator(StatementPtr identifier) : FunctionDeclarator(identifier, new ParameterList()) { }
    std::string getIdentifierName() const override;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
    StatementPtr getIdentifier() const;
    StatementPtr getParamList() const;
    virtual DeclTypeEnum declType() const override { return DeclTypeEnum::func; }
    void printC(std::ostream &os) const override;
};

#endif