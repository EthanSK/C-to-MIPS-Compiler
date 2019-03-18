#ifndef variableInitializationList_hpp 
#define variableInitializationList_hpp

#include "nodeList.hpp"

class VariableInitializationList;
typedef const VariableInitializationList* VariableInitializationListPtr;

class VariableInitializationList : public NodeList
{
public:
    using NodeList::NodeList;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
    virtual void printC(std::ostream &os) const override;
};

#endif
