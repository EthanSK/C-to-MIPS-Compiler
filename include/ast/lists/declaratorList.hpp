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
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;
    int getDeclCount() const;
    DeclaratorPtr getDeclarator(int index) const;

protected:
    void printC(std::ostream &os) const override;
};

#endif