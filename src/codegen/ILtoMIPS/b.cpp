#include "il2mips.hpp"

void IL2MIPS::b(Instr instr, MIPSContext &context) 
{
    context.addRawInstr(Instr("j", instr.dest));
    context.addRawInstr(Instr("nop"));
}