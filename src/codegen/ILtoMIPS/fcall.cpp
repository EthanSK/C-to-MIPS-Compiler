#include "il2mips.hpp"
#include <algorithm>

void IL2MIPS::fcall(Instr instr, MIPSContext &context) 
{
    for (int i = 0; i < instr.extraData.size(); ++i)
    {
        if (i < 4)
        {
            context.addInstr(Instr("move", "$a" + std::to_string(i), instr.extraData[i]));
        }
    }

    int argFrameSize = std::max((int)instr.extraData.size(), 4) * 4;
    context.addRawInstr(Instr("addi", "$sp", "$sp", std::to_string(-argFrameSize), {"#raw"}));
    context.addBranchInstr(Instr("jal", instr.input1), instr.label);
    context.addRawInstr(Instr("addi", "$sp", "$sp", std::to_string(argFrameSize), {"#raw"}));
    context.addInstr(Instr("move", instr.dest, "$v0"));
}