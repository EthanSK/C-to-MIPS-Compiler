#include "ILtoMIPS.hpp"

void ILtoMIPS::convertToMIPS(std::vector<ILinstr> &instrs, std::vector<MIPSinstr> &mipsInstrs)
{
    for (size_t i = 0; i < instrs.size(); i++)
    {
        convertInstr(instrs[i], mipsInstrs)
    }
}

void ILtoMIPS::convertInstr(ILinstr &instr, std::vector<MIPSinstr> &mipsInstr)
{
    if (instr.opcode == "fdef") { ILtoMIPS::fdef(instr, mipsInstr); }
    if (instr.opcode == "fend") { ILtoMIPS::fend(instr, mipsInstr); }
    if (instr.opcode == "fcall") { ILtoMIPS::fcall(instr, mipsInstr); }
    else { throw std::string("Unexpected IL opcode " + instr.opcode + "."); }
}