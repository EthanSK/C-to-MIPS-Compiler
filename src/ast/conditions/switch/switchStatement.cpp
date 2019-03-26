#include "switchStatement.hpp"

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
    // std::string else_lb = context.makeLabelName("else");
    // std::string endif_lb = context.makeLabelName("endif");

    // context.compileInput(getCondition(), instrs, "$t0");
    // instrs.push_back(Instr("bez", else_lb,  "$t0"));
    // getIfScopeBlock()->generateIL(instrs, context, destReg);
    // instrs.push_back(Instr("b", endif_lb));
    // instrs.push_back(Instr::makeLabel(else_lb));
    // getElseScopeBlock()->generateIL(instrs, context, destReg);
    // instrs.push_back(Instr::makeLabel(endif_lb));

    //could loop through cases and default, and make a label for each case
    //we then check if each condition is equal to the case, and if so jump to that label
    //else jump to the default if there is any, or the end of the switch statement
    //we don't have the binary operator like == or > to generate IL on. we have to do it differently to normal if statement. We have to go though every case and check if it is == to it.
    //because there can exist dead code that we do NOT want to execute in the switch statement, when looping, we need to try cast to a switch case node to ensure it is correct. we need to try catch block it so execution continues.
    //we could have an actual switch block node, and that is responsible for looping through the cases and evaluating the correct one, but it would need to know the initial switch case from the parent switch node, which it doesn't know. it only knows its children. therefore we need to somehow access branhces from the switch blokc. maybe make a getter for the scope block?

    // auto scopeBlock = Utils::tryCast<ScopeBlock>(getSwitchBlock(), "switch block must be a scope block");

    // for (size_t i = 0; i < scopeBlock->branches.size(); i++)
    // {
    //     //make a label and block for each switch case

    // }

    //wait, can't we just make the labels in the switch case node?
    //the dest reg in the getSwitchBlock will contain the result. the context could contain the value we are matching against?
    // we can have a stack for switch cases to evaluate in the context, and when tryna figure out the cases it uses the top most stack value.

    //wait what am i on about, we need to know the case at runtime not compile time. it needs to generate labels ad blocks for every case, and do an eq on the genIL on the case dest reg  (return value) and the constant of the switch conditions
    //and that is why we need a for loop, the eq needs to be done on every case (because cases are known at compile time, the are just constants)

    ScopeBlock *switchBlock = Utils::tryCast<ScopeBlock>(getSwitchBlock(), "switch block must be a scope block"); //just to get access to branches
    // switcblock->branches contain all the cases / default

    //first we wanna branch to the correct switch case label. then it will automatically execute everything after that, whic is what we want.
    //we ALWAYS want to execute the scope block of the switch case, because if we have branched there, it means we have ALREADY MET the condition.
    //we just need to be be able to READ the condition from the loop below and add appropriate branches.
    //to find the first switch case, we need to try to cast to switch case in the loop, and get the condition branch (branch[0]), and add the beq/bne whatever it is label
    //we first need to set up all the branches, then after have all the corresponding labels with their blocks. all the branches need to be at the top before.
    //we use switchInstrs to push all the branches at the front of the vector, and all the labels/switch case blocks to the end of the vector
    // acc do we need that?? can't we just bne or somethning after each label

    //OHHHH ok so we only need the  branch stuff if the node is a switch case, otherwise we can just add the IL for the node  and it will work as expected
    for (size_t i = 0; i < switchBlock->getBranches().size(); i++)
    {
        try
        { //is a switch case
            SwitchCase *switchCase = Utils::tryCast<SwitchCase>(switchBlock->getBranches()[i], "node is not a switch case");
            // RValuePtr rvalue = Utils::tryCast<RValue>(switchCase->getCondition(), "condition of switch case must be an rvalue");
            // if (!rvalue->isConstant())
            // {
            //     throw "condition of switch case must be a constant";
            // }
            // int caseConstant = rvalue->evalConst();
            std::string caseSkip_lb = context.makeLabelName("caseSkip_" + std::to_string(caseConstant)); //caseConstant for readability
            std::string switchCaseReg = context.makeName("switchCase");                                  //the a in switch (a)
            getCase()->generateIL(instrs, context, switchCaseReg);
            switchCase->generateIL(instrs, context, "$t0"); //$t0 holds the case condition contsant - the b in case b:
            // instrs.push_back(Instr("bne", caseSkip_lb, switchCaseReg, "$t0"));
            isBranchSwitchCase = true;
            switchCase->getScopeBlock()->generateIL(instrs, context, destReg);
            instrs.push_back(Instr::makeLabel(caseSkip_lb));

            // beq getCase == switchCase.getCondition to caseSkip_lb
            //this ^ can be done inside the switchCase genIL, if the context feeds it the correct getCase to check against.
        }
        catch (const std::exception &e)
        { //not a switch case

            // std::cerr << e.what() << '\n';
            //it actually doesn't matter if it could not be cast, it may very well be valid. this whole try catch acts as an optional cast
            switchBlock->getBranches()[i]->generateIL(instrs, context, destReg);
        }
        //scope IL should be added here, for every node! except the ones before the first case, that's ded. or we can generate the first branch instruction at hte very top of the switch insrts

        //the label should go after that then if there is a label
    }
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