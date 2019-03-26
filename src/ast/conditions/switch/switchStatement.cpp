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
    std::string switchEnd_lb = context.makeName("switchEnd"); //the a in switch (a)

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
                SwitchDefaultPtr switchDefault = Utils::tryCast<SwitchDefault>(switchBlockBranches[i], "node is not a default class");
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
        { //not a switch case
        }
    }
    if (hasDefault)
    {
        instrs.push_back(branchToDefaultInstr);
    }
    instrs.push_back(Instr("b", switchEnd_lb));

    //now set up the branch labels with the corresponding block IL
    int labelIndex = 0;
    for (size_t i = 0; i < switchBlockBranches.size(); i++)
    {
        //if there is corresponding label for node, make label
        try
        { //is a switch case
            SwitchCasePtr switchCase = Utils::tryCast<SwitchCase>(switchBlockBranches[i], "node is not a switch case");
            std::string label = labels[labelIndex++];
            instrs.push_back(Instr::makeLabel(label));
            switchCase->getScopeBlock()->generateIL(instrs, context, destReg);
            //need to somehow store the label for later us
        }
        catch (std::string)
        { //not a switch case
            switchBlockBranches[i]->generateIL(instrs, context, destReg);
        }
    }
    instrs.push_back(Instr::makeLabel(switchEnd_lb));

    //then after we have set all the labels with their blocks, we need to do an eq to jump to the correct block
    //we can do a beq as it is in our IL spec.
    //we need to beq to the label if the switch case constant value is eq to the getCase constant value .that should actually be done i nthe for loop as we need to check it for each case.

    // context.compileInput(getCase(), instrs, "$t0"); //case we wanna match against is stored in t0. we wanna do an eq
    // instrs.push_back(Instr("eq", "$t1", "$t0"));

    //wont work
    // context.pushSwitchCase(getCase());

    // getSwitchBlock()->generateIL(instrs, context, destReg); //will be switchBlock implementeation of genIL, which loops through all VALID cases and genIL on those

    // context.popSwitchCase();
}