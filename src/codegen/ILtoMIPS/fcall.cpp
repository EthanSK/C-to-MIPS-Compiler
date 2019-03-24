#include "il2mips.hpp"
#include <algorithm>

void IL2MIPS::fcall(Instr instr, MIPSContext &context) 
{
    for (size_t i = 0; i < instr.extraData.size(); ++i)
    {
        if (i < 4) { context.addInstr(Instr("move", "$a" + std::to_string(i), instr.extraData[i])); }
        else { context.addInstr(Instr("move", "_farg" + std::to_string(i), instr.extraData[i])); }    
    }

    for (size_t i = instr.extraData.size() - 1; i > 3; --i)
    {
        context.alloc(Allocation(4, "_arg" + std::to_string(i)));
        context.addInstr(Instr("move", "_arg" + std::to_string(i), "_farg" + std::to_string(i)));
    }

    int argFrameSize = 4 * 4;
    context.addRawInstr(Instr("addi", "$sp", "$sp", std::to_string(-argFrameSize), {"#raw"}));
    context.addBranchInstr(Instr("jal", instr.input1), instr.label);
    context.addRawInstr(Instr("addi", "$sp", "$sp", std::to_string(argFrameSize), {"#raw"}));
    context.addInstr(Instr("move", instr.dest, "$v0"));
}