#include "il2mips.hpp"

void IL2MIPS::fcall(Instr instr, MIPSContext &context) 
{
    context.addBranchInstr(Instr("jal", instr.input1), instr.label);
    context.addInstr(Instr("move", instr.dest, "$v0"));
}