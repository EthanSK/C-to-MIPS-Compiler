#include "il2mips.hpp"

void IL2MIPS::fcall(Instr instr, MIPSContext &context) 
{
    for (int i = 0; i < instr.extraData.size(); ++i)
    {
        if (i < 4)
        {
            context.addInstr(Instr("move", "$a" + std::to_string(i), instr.extraData[i]));
        }
    }

    context.addBranchInstr(Instr("jal", instr.input1), instr.label);
    context.addInstr(Instr("move", instr.dest, "$v0"));
}