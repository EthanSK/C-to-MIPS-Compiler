#ifndef declaratorList_hpp 
#define declaratorList_hpp

#include "nodeList.hpp"

class DeclaratorList;
typedef const DeclaratorList* DeclaratorListPtr;

class DeclaratorList : public NodeList
{
public:
    using NodeList::NodeList;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
    virtual void printC(std::ostream &os) const override;
};

#endif