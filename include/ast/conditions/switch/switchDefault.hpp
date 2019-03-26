#ifndef switchDefault_hpp
#define switchDefault_hpp

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "statement.hpp"

class SwitchDefault : public Statement
{
public:
    SwitchDefault(StatementPtr scopeBlock);
    void generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const override;

protected:
	StatementPtr getScopeBlock() const; //execution block 

    void printC(std::ostream &os) const override;
};

#endif
