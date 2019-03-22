#include "ternaryOperator.hpp"

TernaryOperator::TernaryOperator(StatementPtr condition, StatementPtr trueSelect, StatementPtr falseSelect)
{
        branches.push_back(condition);
        branches.push_back(trueSelect);
        branches.push_back(falseSelect);
} 

StatementPtr TernaryOperator::getCondition() const
{
        return branches[0];
}

StatementPtr TernaryOperator::getTrueSelect() const
{
        return branches[1];
}

StatementPtr TernaryOperator::getFalseSelect() const
{
        return branches[2];
}

void TernaryOperator::printC(std::ostream &os) const{
    os << "(" << getCondition() << ") ? " << getTrueSelect() << " : " << getFalseSelect();
}

void TernaryOperator::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    std::string conditionReg = context.makeName("cond");
    std::string else_lb = context.makeName("else");
    std::string endif_lb = context.makeName("endif");

    getCondition()->generateIL(instrs, context, conditionReg);
    instrs.push_back(Instr("bnez", else_lb, conditionReg));
    getTrueSelect()->generateIL(instrs, context, destReg);
    instrs.push_back(Instr("b", endif_lb));
    instrs.push_back(Instr::makeLabel(else_lb));
    getFalseSelect()->generateIL(instrs, context, destReg);
    instrs.push_back(Instr::makeLabel(endif_lb));
}