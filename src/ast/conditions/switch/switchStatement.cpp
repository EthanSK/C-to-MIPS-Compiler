#include "switchStatement.hpp"
#include "switchCase.hpp"
#include "switchDefault.hpp"

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
    ScopeBlockPtr switchBlock = Utils::tryCast<ScopeBlock>(getSwitchBlock(), "switch block must be a scope block"); //just to get access to branches
    std::vector<StatementPtr> switchBlockBranches = switchBlock->getBranches();
    std::string switchEnd_lb = context.makeLabelName("switchEnd"); //the a in switch (a)
    context.pushLoopLabels("NULL", switchEnd_lb);

    //we could set up labels and scope blocks first, the branch past all that, then beq back...nah would mess up at the end.

    //first set up beq's for switch cases
    //keep track of labels being created, maybe ith a map of nodeid : label ?
    std::vector<std::string> labels;
    Instr branchToDefaultInstr;
    bool hasDefault = false;
    for (size_t i = 0; i < switchBlockBranches.size(); i++)
    {
        try
        { //is a switch case (or default)
            SwitchCasePtr switchCase = Utils::tryCast<SwitchCase>(switchBlockBranches[i], "node is not a switch case");
            std::string switchCaseReg = context.makeName("switchCase"); //the a in switch (a)
            std::string case_lb = context.makeLabelName("case_lb");

            try
            { //is default
                Utils::tryCast<SwitchDefault>(switchBlockBranches[i], "node is not a default class");
                hasDefault = true;
                branchToDefaultInstr = Instr("b", case_lb);
            }
            catch (std::string)
            { //is not default
                getCase()->generateIL(instrs, context, switchCaseReg);
                switchCase->generateIL(instrs, context, "$t0"); //switch case generateIL just returns the condition constant
                instrs.push_back(Instr("beq", case_lb, switchCaseReg, "$t0"));
            }
            labels.push_back(case_lb); //even if it's from default, it should stay in place as if there is no break it can continue executing the other lines
        }
        catch (std::string)
        { //not a switch case or default
        }
    }
    if (hasDefault)
    {
        instrs.push_back(branchToDefaultInstr);
    }
    instrs.push_back(Instr("b", switchEnd_lb));

    //now set up the branch labels with the corresponding block IL
    int labelIndex = 0;
    bool deadCode = true;
    for (size_t i = 0; i < switchBlockBranches.size(); i++)
    {
        //if there is corresponding label for node, make label
        try
        { //is a switch case or default
            SwitchCasePtr switchCase = Utils::tryCast<SwitchCase>(switchBlockBranches[i], "node is not a switch case");
            deadCode = false;
            std::string label = labels[labelIndex++];
            instrs.push_back(Instr::makeLabel(label));
            switchCase->getScopeBlock()->generateIL(instrs, context, destReg);
            //need to somehow store the label for later us
        }
        catch (std::string)
        { //not a switch case or default
            if (!deadCode)
            {
                switchBlockBranches[i]->generateIL(instrs, context, destReg);
            }
        }
    }
    instrs.push_back(Instr::makeLabel(switchEnd_lb));
    context.popLoopLabels();
}