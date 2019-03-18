#ifndef variableDeclarator_hpp
#define variableDeclarator_hpp

#include "declarator.hpp"

class VariableDeclarator : public Declarator
{
public:
    VariableDeclarator(StatementPtr identifier);
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    std::string getIdentifierName() const override;

protected:
    StatementPtr getIdentifier() const;
    void printC(std::ostream &os) const override;
};

#endif