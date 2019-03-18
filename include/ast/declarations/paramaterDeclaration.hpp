#ifndef paramaterDeclaration_hpp
#define paramaterDeclaration_hpp

#include "declaration.hpp"

class ParamaterDeclaration : public Declaration
{
public:
    ParamaterDeclaration(StatementPtr type, StatementPtr identifier);
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  
protected:
    StatementPtr getType() const;
    StatementPtr getIdentifier() const;

    virtual void printC(std::ostream &os) const override;
};

#endif