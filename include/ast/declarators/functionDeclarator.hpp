#ifndef functionDeclarator_hpp
#define functionDeclarator_hpp

#include "declarator.hpp"

class FunctionDeclarator : public Declarator
{
public:
    FunctionDeclarator(StatementPtr identifier, StatementPtr paramList);
    std::string getIdentifierName() const override;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
    StatementPtr getIdentifier() const;
    StatementPtr getParamList() const;
    void printC(std::ostream &os) const override;
};

#endif