#ifndef expressionList_hpp 
#define expressionList_hpp

#include "nodeList.hpp"

class ExpressionList;
typedef const ExpressionList* ExpressionListPtr;

class ExpressionList : public NodeList
{
public:
    using NodeList::NodeList;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
    virtual void printC(std::ostream &os) const override;
};

#endif
