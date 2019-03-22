#include "il2mips.hpp"

void IL2MIPS::fend(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("jr", "$ra"));
    context.addInstr(Instr("nop"));
}