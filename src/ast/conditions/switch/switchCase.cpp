#include "switchCase.hpp"

SwitchCase::SwitchCase(StatementPtr condition, StatementPtr scopeBlock)
{
    branches.push_back(condition);
    branches.push_back(scopeBlock);
}

StatementPtr SwitchCase::getCondition() const
{
    return branches[0];
}
StatementPtr SwitchCase::getScopeBlock() const
{
    return branches[1];
}
void SwitchCase::printC(std::ostream &os) const
{
    os << "case " << getCondition() << ": " << getScopeBlock(); //wont technically be correct as scope block in case doesn't have {} but doesn't really matter for printing
}

void SwitchCase::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
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