#include "switchBlock.hpp"


void SwitchBlock::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    instrs.push_back(Instr("scu"));
    for (size_t i = 0; i < branches.size(); i++)
    {
        try
        { //doing try because dead code is still valid and compilation should continue
            Utils::tryCast<SwitchCase>(branches[i], "node is not a switch case, it is either dead code or invalid"); //don't care about return value of cast, only care that it can cast
            //only generate IL on valid branches that aren't dead code
            branches[i]->generateIL(instrs, context, destReg);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    instrs.push_back(Instr("scd"));
}
