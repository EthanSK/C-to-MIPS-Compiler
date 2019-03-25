#include "continueKeyword.hpp"


void ContinueKeyword::printC(std::ostream &os) const
{
    os << "continue";
}

void ContinueKeyword::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    //need to jump to label of begining of function, which can be found in context
    std::string endLoopLabel = std::get<0>(context.getLastLoopLabel());
    instrs.push_back(Instr("b", endLoopLabel));
}
