#ifndef variableDeclaration_hpp
#define variableDeclaration_hpp

#include "declaration.hpp"
#include "variableInitializationList.hpp"

class VariableDeclaration : public Declaration
{
public:
    VariableDeclaration(StatementPtr type, NodeListPtr initList);
    VariableDeclaration(StatementPtr type, std::vector<StatementPtr> initList) : VariableDeclaration(type, new VariableInitializationList(initList)) { }
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
  
protected:
    StatementPtr getType() const;
    StatementPtr getInitList() const;

    virtual void printC(std::ostream &os) const override;
};

#endif