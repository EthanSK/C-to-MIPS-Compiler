#include "il2mips.hpp"

void IL2MIPS::bne(Instr instr, MIPSContext &context) 
{
    context.addBranchInstr(Instr("bne", instr.input1, instr.input2, instr.dest), instr.label);
}