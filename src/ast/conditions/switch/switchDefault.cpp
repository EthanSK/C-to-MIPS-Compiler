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
    //   RValuePtr rvalue = Utils::tryCast<RValue>(getCondition(), "condition of switch case must be an rvalue");
    // if (!rvalue->isConstant())
    // {
    //     throw "condition of switch case must be a constant";
    // }
    // int caseConstant = rvalue->evalConst();
    // std::string case_lb = context.makeLabelName("case_" + std::to_string(caseConstant)); //caseConstant for prettyness
    // std::string switchCaseReg = context.makeName("switchCase");                          //the a in switch (a)
    // std::string caseConditionReg = context.makeName("switchCondition");                  //the b in case b:
    // context.getLastSwitchCase()->generateIL(instrs, context, switchCaseReg);             //evaluate and put in temp reg (like defining a variable)
    // // put caseConstant in temp reg too (with li)
    // instrs.push_back(Instr("li", caseConditionReg, std::to_string(caseConstant)));
    // // then compare the two reg's
    // instrs.push_back(Instr("beq", case_lb, switchCaseReg, caseConditionReg));
    // instrs.push_back(Instr::makeLabel(case_lb));
    // getScopeBlock()->generateIL(instrs, context, destReg);
}