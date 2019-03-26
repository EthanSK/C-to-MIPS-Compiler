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

    auto switchBlock = Utils::tryCast<ScopeBlock>(getSwitchBlock(), "switch block must be a scope block"); //just to get access to branches
    // switcblock->branches contain all the cases / default

    for (size_t i = 0; i < switchBlock->branches.size(); i++)
    {
        //make a label and block for each switch case (check if its actually a switch case)
        try
        { //doing try because dead code is still valid and compilation should continue
            auto switchCase = Utils::tryCast<SwitchCase>(switchBlock->branches[i], "node is not a switch case, it is either dead code or invalid");
            std::string case_lb = context.makeLabelName("case");
            instrs.push_back(Instr::makeLabel(else_lb));
            switchCase->generateIL(instrs, context, destReg);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    //then after we have set all the labels with their blocks, we need to do an eq to jump to the correct block
    //we can do a beq as it is in our IL spec. 
    //we need to beq to the label if the switch case constant value is eq to the getCase constant value .that should actually be done i nthe for loop as we need to check it for each case.

    context.compileInput(getCase(), instrs, "$t0"); //case we wanna match against is stored in t0. we wanna do an eq
    instrs.push_back(Instr("eq", "$t1", "$t0"));

    // 	std::string opcode = "eq";
    // std::string leftReg = context.makeName(opcode + "_l");
    // std::string rightReg = context.makeName(opcode + "_r");
    // context.compileInput(getLeft(), instrs, leftReg);
    // context.compileInput(getRight(), instrs, rightReg);
    // instrs.push_back(Instr(opcode, destReg, leftReg, rightReg));

    getSwitchBlock()->generateIL(instrs, context, destReg);
}