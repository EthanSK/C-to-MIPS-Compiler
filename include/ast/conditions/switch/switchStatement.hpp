#ifndef switch_hpp
#define switch_hpp

#include <vector> 
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"
#include "scopeBlock.hpp"

#include "utils.hpp" 

class SwitchStatement;
typedef const SwitchStatement* SwitchStatementPtr;

class SwitchStatement : public Statement 
{
public:
    SwitchStatement(StatementPtr caseExpr, StatementPtr switchBlock);
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;

protected:
    StatementPtr getCase() const; //as in the a in switch(a)
	StatementPtr getSwitchBlock() const; //contains cases and maybe default. just a regular scope block

    void printC(std::ostream &os) const override;
};

#endif
