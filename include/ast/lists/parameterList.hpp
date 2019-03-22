#ifndef parameterList_hpp 
#define parameterList_hpp

#include "nodeList.hpp"

class ParameterList;
typedef const ParameterList* ParameterListPtr;

class ParameterList : public NodeList
{
public:
    using NodeList::NodeList;
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;

protected:
    virtual void printC(std::ostream &os) const override;
};

#endif
