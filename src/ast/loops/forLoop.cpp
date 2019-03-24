#include "forLoop.hpp"

ForLoop::ForLoop(StatementPtr init, StatementPtr condition, StatementPtr increment, StatementPtr scopeBlock)
{
    branches.push_back(init);
    branches.push_back(condition);
    branches.push_back(increment);
    branches.push_back(scopeBlock);
} 
StatementPtr ForLoop::getInit() const
{
    return branches[0];
}
StatementPtr ForLoop::getCondition() const
{
    return branches[1];
}
StatementPtr ForLoop::getIncrement() const
{
    return branches[2];
}
StatementPtr ForLoop::getScopeBlock() const
{
    return branches[3];
}

void ForLoop::printC(std::ostream &os) const
{
    os << "for (" << getInit() << "; " << getCondition() << "; " << getIncrement() << ")" << getScopeBlock();
}

void ForLoop::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    std::string forCond = context.makeName("cond");
    std::string for_lb = context.makeLabelName("for");
    std::string for_end_lb = context.makeLabelName("for_end");

    getInit()->generateIL(instrs, context, destReg);

    instrs.push_back(Instr::makeLabel(for_lb));
    context.compileInput(getCondition(), instrs, forCond);
    instrs.push_back(Instr("bez", for_end_lb, forCond));

    getScopeBlock()->generateIL(instrs, context, destReg);
    getIncrement()->generateIL(instrs, context, destReg);
    instrs.push_back(Instr("b", for_lb));
    instrs.push_back(Instr::makeLabel(for_end_lb));
}