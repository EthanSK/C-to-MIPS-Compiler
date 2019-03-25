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

void IfElseStatement::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    std::string else_lb = context.makeLabelName("else");
    std::string endif_lb = context.makeLabelName("endif");

    context.compileInput(getCondition(), instrs, "$t0");
    instrs.push_back(Instr("bez", else_lb,  "$t0"));
    getIfScopeBlock()->generateIL(instrs, context, destReg);
    instrs.push_back(Instr("b", endif_lb));
    instrs.push_back(Instr::makeLabel(else_lb));
    getElseScopeBlock()->generateIL(instrs, context, destReg);
    instrs.push_back(Instr::makeLabel(endif_lb));
}