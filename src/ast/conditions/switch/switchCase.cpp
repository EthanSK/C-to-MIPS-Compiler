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
    std::string caseSkip_lb = context.makeLabelName("caseSkip_" + std::to_string(caseConstant)); //caseConstant for prettyness
    std::string switchCaseReg = context.makeName("switchCase");                          //the a in switch (a)            //the b in case b:
    context.getLastSwitchCase()->generateIL(instrs, context, switchCaseReg);             //evaluate and put in temp reg (like defining a variable)
    // put caseConstant in temp reg too (with li)
    instrs.push_back(Instr("li", "$t0", std::to_string(caseConstant)));
    // then compare the two reg's
    instrs.push_back(Instr("bne", caseSkip_lb, switchCaseReg, "$t0"));
    getScopeBlock()->generateIL(instrs, context, destReg);
    instrs.push_back(Instr::makeLabel(caseSkip_lb));
}