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
    RValuePtr rvalue = Utils::tryCast<RValue>(getCondition(), "condition of switch case must be an rvalue");
    if (!rvalue->isConstant()) { throw "condition of switch case must be a constant"; }

    int caseConstant = rvalue->evalConst();
    instrs.push_back(Instr("li", destReg, std::to_string(caseConstant)));//switch case returned through destReg
}