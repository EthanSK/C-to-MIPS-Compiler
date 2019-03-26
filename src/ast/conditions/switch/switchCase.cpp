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
    if (!rvalue->isConstant()) 
    {
        throw "condition of switch case must be a constant";
    }

    int caseConstant = rvalue->evalConst();
    std::string case_lb = context.makeLabelName("case_" + std::to_string(caseConstant)); //caseConstant for prettyness
    //getScopeBlock()->generateIL(instrs, context, destReg);

    // instrs.push_back(Instr("decla", getIdentifierName(), std::to_string(arraySize * 4)));
}