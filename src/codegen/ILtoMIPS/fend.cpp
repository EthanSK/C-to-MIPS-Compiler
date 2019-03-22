#include "il2mips.hpp"

void IL2MIPS::fend(Instr instr, MIPSContext &context) 
{
    context.popFrame();
    context.addInstr(Instr("jr", "$ra"));
    context.addInstr(Instr("nop"));
}