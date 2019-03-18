#ifndef parameterDeclaration_hpp
#define parameterDeclaration_hpp

#include "declaration.hpp"

class ParameterDeclaration : public Declaration
{
public:
    ParameterDeclaration(StatementPtr type, StatementPtr decl);
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  
protected:
    StatementPtr getType() const;
    StatementPtr getDecl() const;

    virtual void printC(std::ostream &os) const override;
};

#endif