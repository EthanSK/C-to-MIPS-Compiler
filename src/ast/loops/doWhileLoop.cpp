#include "doWhileLoop.hpp"

DoWhileLoop::DoWhileLoop(StatementPtr scopeBlock, StatementPtr condition){
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

void DoWhileLoop::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    std::string whileCond = context.makeName("cond");
    std::string while_lb = context.makeName("while");

    instrs.push_back(ILinstr(while_lb));
    getScopeBlock()->generateIL(instrs, context, destReg);

    getCondition()->generateIL(instrs, context, whileCond);
    instrs.push_back(ILinstr("bnez", while_lb, whileCond));
}