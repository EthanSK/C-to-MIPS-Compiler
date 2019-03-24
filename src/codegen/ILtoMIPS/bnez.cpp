#include "il2mips.hpp"

void IL2MIPS::bnez(Instr instr, MIPSContext &context) 
{
    context.addBranchInstr(Instr("bne", instr.input1, "$0", instr.dest), instr.label);
}