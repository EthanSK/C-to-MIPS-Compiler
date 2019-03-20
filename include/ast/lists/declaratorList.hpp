#ifndef declaratorList_hpp 
#define declaratorList_hpp

#include "nodeList.hpp"
#include "declarator.hpp"

class DeclaratorList;
typedef const DeclaratorList* DeclaratorListPtr;

class DeclaratorList : public NodeList
{
public:
    using NodeList::NodeList;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;

protected:
    DeclaratorPtr getDeclarator(int index) const;
    void printC(std::ostream &os) const override;
};

#endif