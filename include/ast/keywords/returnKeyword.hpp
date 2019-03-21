#ifndef returnKeyword_hpp
#define returnKeyword_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class ReturnKeyword : public Statement
{
public:
    ReturnKeyword(StatementPtr returnValue);
    void generatePython(std::ostream &os, PythonContext &context, int scopeDepth = 0) const override;
    void generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const override;

protected:
    StatementPtr getReturnValue() const;
    void printC(std::ostream &os) const override;
};

#endif
