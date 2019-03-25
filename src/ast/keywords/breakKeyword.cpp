#include "breakKeyword.hpp"

void BreakKeyword::printC(std::ostream &os) const
{
    os << "break";
}

void BreakKeyword::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    //need to jump to label of end of function, which can be found in context
    std::string endLoopLabel = std::get<1>(context.getLastLoopLabel());
    instrs.push_back(Instr("b", endLoopLabel));
}
