#include "ILtoMIPS.hpp"

void ILtoMIPS::convertToMIPS(std::vector<ILinstr> &instrs, std::vector<MIPSinstr> &mipsInstr)
{
    for (size_t i = 0; i < instrs.size(); i++)
    {
        if (instrs[i].opcode == "fdef")
        {
            ILtoMIPS::fdef(instrs[i], mipsInstr);
        }
        if (instrs[i].opcode == "fend")
        {
            ILtoMIPS::fend(instrs[i], mipsInstr);
        }
        if (instrs[i].opcode == "fcall")
        {
            ILtoMIPS::fcall(instrs[i], mipsInstr);
        }
    }
}