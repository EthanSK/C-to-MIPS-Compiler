#include "switchDefault.hpp"
#include "integerLiteral.hpp"

SwitchDefault::SwitchDefault(StatementPtr scopeBlock) : SwitchCase(new IntegerLiteral(1), scopeBlock)
{

}

StatementPtr SwitchDefault::getScopeBlock() const
{
    return branches[1];
}

void SwitchDefault::printC(std::ostream &os) const
{
    os << "default: " << getScopeBlock(); 
}

void SwitchDefault::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    //do nothing - there is no constant to evaluate and scope block generated from switch statement loop
}