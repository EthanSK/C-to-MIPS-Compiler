#ifndef variableInitializationList_hpp 
#define variableInitializationList_hpp

#include "statement.hpp"

class VariableInitializationList : public Statement
{
  public:
    VariableInitializationList(std::vector<StatementPtr> initializations);
    std::vector<StatementPtr> getInitializations() const;
    virtual void printC(std::ostream &os) const override = 0;
};

#endif