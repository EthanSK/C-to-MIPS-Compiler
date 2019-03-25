#include "doWhileLoop.hpp"

DoWhileLoop::DoWhileLoop(StatementPtr scopeBlock, StatementPtr condition)
{
    branches.push_back(scopeBlock);
    branches.push_back(condition);
}
StatementPtr DoWhileLoop::getScopeBlock() const
{
    return branches[0];
}
StatementPtr DoWhileLoop::getCondition() const
{
    return branches[1];
}

void DoWhileLoop::printC(std::ostream &os) const
{
    os << "do" << getScopeBlock() << "while ( " << getCondition() << ")";
}

void DoWhileLoop::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    std::string whileCond = context.makeName("cond");
    std::string while_lb = context.makeLabelName("while");
    std::string whileEnd_lb = context.makeLabelName("while_end");

    context.pushLoopLabels(while_lb, whileEnd_lb);

    instrs.push_back(Instr::makeLabel(while_lb));
    getScopeBlock()->generateIL(instrs, context, destReg);

    context.compileInput(getCondition(), instrs, whileCond);
    instrs.push_back(Instr("bnez", while_lb, whileCond));
    instrs.push_back(Instr::makeLabel(whileEnd_lb));
    context.popLoopLabels();
}