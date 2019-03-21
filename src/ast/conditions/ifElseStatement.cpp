#include "ifElseStatement.hpp"

IfElseStatement::IfElseStatement(StatementPtr condition, StatementPtr ifScopeBlock, StatementPtr elseScopeBlock)
{
    branches.push_back(condition);
    branches.push_back(ifScopeBlock);
    branches.push_back(elseScopeBlock);
}

StatementPtr IfElseStatement::getCondition() const
{
    return branches[0];
}
StatementPtr IfElseStatement::getIfScopeBlock() const
{
    return branches[1];
}
StatementPtr IfElseStatement::getElseScopeBlock() const
{
    return branches[2];
}
void IfElseStatement::printC(std::ostream &os) const
{
    os << "if (" << getCondition() << ")" << getIfScopeBlock() << std::endl
       << "else " << getElseScopeBlock(); //the scopeBlock printC is repsonsible for printing the { } with new lines
}

void IfElseStatement::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << "if ";
    getCondition()->generatePython(os, context, scopeDepth);
    os << ":";

    getIfScopeBlock()->generatePython(os, context, scopeDepth + 1);

    context.indentStream(os, scopeDepth);
    os << "else:";
    getElseScopeBlock()->generatePython(os, context, scopeDepth + 1);
}

void IfElseStatement::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    std::string conditionReg = "conditionReg";
    std::string ifLabel = "ifLabel"; //makename - needs to be unique
    std::string endLabel = "endLabel";
    
    getCondition()->generateIL(instrs, context, conditionReg); //sets up condition, result is 1 or 0
    //need to generate labels for branch
    instrs.push_back(ILinstr("branchIfEqual", ifLabel, conditionReg, "true_immediate_goes_here"));
    getElseScopeBlock()->generateIL(instrs, context, "doesnt_matter");
    instrs.push_back(ILinstr(endLabel));
    instrs.push_back(ILinstr(ifLabel));
    getIfScopeBlock()->generateIL(instrs, context, "doesnt_matter");
    instrs.push_back(ILinstr(endLabel)); //no need, just for consistency & safety
}