#include "switchDefault.hpp"

SwitchDefault::SwitchDefault(StatementPtr scopeBlock)
{
    branches.push_back(scopeBlock);
} 

StatementPtr SwitchDefault::getScopeBlock() const
{
    return branches[0];
}

void SwitchDefault::printC(std::ostream &os) const
{
    os << "default: " << getScopeBlock(); 
}

void SwitchDefault::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    // std::string else_lb = context.makeLabelName("else");
    // std::string endif_lb = context.makeLabelName("endif");

    // context.compileInput(getCondition(), instrs, "$t0");
    // instrs.push_back(Instr("bez", else_lb,  "$t0"));
    // getIfScopeBlock()->generateIL(instrs, context, destReg);
    // instrs.push_back(Instr("b", endif_lb));
    // instrs.push_back(Instr::makeLabel(else_lb));
    // getElseScopeBlock()->generateIL(instrs, context, destReg);
    // instrs.push_back(Instr::makeLabel(endif_lb));
}