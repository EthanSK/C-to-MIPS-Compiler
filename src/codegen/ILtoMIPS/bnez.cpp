#include "il2mips.hpp"

void IL2MIPS::bnez(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("bne", instr.input1, "$0", instr.dest));
    context.addRawInstr(Instr("nop"));
}