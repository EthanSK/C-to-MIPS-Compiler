#ifndef variableInitializationList_hpp 
#define variableInitializationList_hpp

#include "statement.hpp"

class VariableInitializationList : public Statement
{
public:
    VariableInitializationList(std::vector<StatementPtr> initializations);
    std::vector<StatementPtr> getInitializations() const;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
    virtual void printC(std::ostream &os) const override;
};

#endif