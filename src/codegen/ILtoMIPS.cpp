#include "ILtoMIPS.hpp"

void ILtoMIPS::convertToMIPS(std::vector<ILinstr> &instrs, std::vector<MIPSinstr> &mipsInstrs)
{
    MIPSContext context;
    convertToMIPS(instrs, context, mipsInstrs);
}

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
    else if (instr.opcode == "fend") { ILtoMIPS::fend(instr, context, mipsInstr); }
    else if (instr.opcode == "fcall") { ILtoMIPS::fcall(instr, context, mipsInstr); }
    else if (instr.opcode == "scu") { ILtoMIPS::scu(instr, context, mipsInstr); }
    else if (instr.opcode == "scd") { ILtoMIPS::scd(instr, context, mipsInstr); }
    else if (instr.opcode == "decl") { ILtoMIPS::decl(instr, context, mipsInstr); }
    else { throw std::string("Unexpected IL opcode " + instr.opcode + "."); }
}