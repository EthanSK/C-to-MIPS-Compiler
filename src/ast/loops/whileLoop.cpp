#include "whileLoop.hpp"

WhileLoop::WhileLoop(StatementPtr condition, StatementPtr scopeBlock){
    branches.push_back(condition);
    branches.push_back(scopeBlock); 
}

StatementPtr WhileLoop::getCondition() const{
    return branches[0];
}
StatementPtr WhileLoop::getScopeBlock() const{
    return branches[1];
}

void WhileLoop::printC(std::ostream &os) const 
{
    os << "while (" << getCondition() << ")" << getScopeBlock(); 
}

void WhileLoop::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "while ";
    getCondition()->generatePython(os, context, scopeDepth);
    os << ":";
    getScopeBlock()->generatePython(os, context, scopeDepth + 1);
}

void WhileLoop::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    std::string while_lb = context.makeLabelName("while");
    std::string while_end_lb = context.makeLabelName("while_end");
    context.pushLoopLabels(while_lb, while_end_lb);

    instrs.push_back(Instr::makeLabel(while_lb));
    context.compileInput(getCondition(), instrs, "$t0");
    instrs.push_back(Instr("bez", while_end_lb, "$t0"));

    getScopeBlock()->generateIL(instrs, context, destReg);
    instrs.push_back(Instr("b", while_lb));
    instrs.push_back(Instr::makeLabel(while_end_lb));
    context.popLoopLabels();
}

