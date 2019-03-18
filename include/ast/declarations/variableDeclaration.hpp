#ifndef variableDeclaration_hpp
#define variableDeclaration_hpp

#include "declaration.hpp"
#include "identifier.hpp"

class VariableDeclaration : public Declaration
{
public:
    VariableDeclaration(StatementPtr type, StatementPtr initList);
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  
protected:
    StatementPtr getType() const;
    StatementPtr getInitList() const;
    std::vector<StatementPtr> getInitializations() const;

    virtual void printC(std::ostream &os) const override;
};

#endif