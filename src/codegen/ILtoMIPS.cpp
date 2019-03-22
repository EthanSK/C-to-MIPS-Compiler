#include "ILtoMIPS.hpp"

void ILtoMIPS::convertToMIPS(std::vector<ILinstr> &instrs, MIPSContext &context, std::vector<MIPSinstr> &mipsInstrs)
{
    for (size_t i = 0; i < instrs.size(); i++)
    {
        convertInstr(instrs[i], context, mipsInstrs);
    }
}

void ILtoMIPS::convertInstr(ILinstr &instr, MIPSContext &context, std::vector<MIPSinstr> &mipsInstr)
{
    if (instr.opcode == "fdef") { ILtoMIPS::fdef(instr, context, mipsInstr); }
    if (instr.opcode == "fend") { ILtoMIPS::fend(instr, context, mipsInstr); }
    if (instr.opcode == "fcall") { ILtoMIPS::fcall(instr, context, mipsInstr); }
    else { throw std::string("Unexpected IL opcode " + instr.opcode + "."); }
}