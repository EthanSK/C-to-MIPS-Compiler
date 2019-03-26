#include "switchStatement.hpp"

SwitchStatement::SwitchStatement(StatementPtr caseExpr, StatementPtr switchBlock)
{
    branches.push_back(caseExpr);
    branches.push_back(switchBlock);
}

StatementPtr SwitchStatement::getCase() const
{
    return branches[0];
}
StatementPtr SwitchStatement::getSwitchBlock() const
{
    return branches[1];
}
void SwitchStatement::printC(std::ostream &os) const
{
    os << "switch (" << getCase() << ")" << getSwitchBlock(); //getSwitchBlock is a regular scope block
}

void SwitchStatement::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
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