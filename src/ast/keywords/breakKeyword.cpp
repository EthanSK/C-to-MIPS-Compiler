#include "breakKeyword.hpp"

void BreakKeyword::printC(std::ostream &os) const
{
    os << "break";
}

void BreakKeyword::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    //need to jump to label of end of function, which can be found in context
    instrs.push_back(Instr("b", for_lb));

}
