#ifndef switch_hpp
#define switch_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "scopeBlock.hpp"

class SwitchStatement : public Statement 
{
public:
    SwitchStatement(StatementPtr caseExpr, StatementPtr scopeBlock);
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;

protected:
    StatementPtr getCase() const; //as in the a in switch(a)
    StatementPtr getScopeBlock() const;

    void printC(std::ostream &os) const override;
};

#endif
