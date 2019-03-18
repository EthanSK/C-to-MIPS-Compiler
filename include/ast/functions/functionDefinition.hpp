#ifndef functionDefinition_hpp
#define functionDefinition_hpp

#include <iostream>
#include "statement.hpp"
#include "identifier.hpp"

class FunctionDefinition : public Statement
{
public:
    FunctionDefinition(StatementPtr decl, StatementPtr scopeBlock);
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
    StatementPtr getDecl() const;
    StatementPtr getScopeBlock() const;
    void printC(std::ostream &os) const override;
};

#endif