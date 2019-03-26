#include "il2mips.hpp"
#include <algorithm>

void IL2MIPS::fcall(Instr instr, MIPSContext &context) 
{
    for (size_t i = 0; i < instr.extraData.size(); ++i)
    {
        if (i < 4) { context.addInstr(Instr("move", "$a" + std::to_string(i), instr.extraData[i])); }
        else { context.addInstr(Instr("move", "_farg" + std::to_string(i), instr.extraData[i])); }    
    }

    for (int i = instr.extraData.size() - 1; i > 3; --i)
    {
        context.alloc(Allocation(4, "_arg" + std::to_string(i)));
        context.addInstr(Instr("move", "_arg" + std::to_string(i), "_farg" + std::to_string(i)));
    }

    int argFrameSize = 4 * 4;
    context.addRawInstr(Instr("addi", "$sp", "$sp", std::to_string(-argFrameSize), {"#raw"}));
    context.addRawInstr(Instr("lw", "$gp", "__gnu_local_gp"));
    context.addRawInstr(Instr("lw", "$t0", "%call16(" + instr.input1 + ")($gp)"));
    context.addRawInstr(Instr("nop"));
    context.addRawInstr(Instr("jalr", "$t0"));
    context.addRawInstr(Instr("nop"));
    context.addRawInstr(Instr("addi", "$sp", "$sp", std::to_string(argFrameSize), {"#raw"}));
    context.addInstr(Instr("move", instr.dest, "$v0"));
}