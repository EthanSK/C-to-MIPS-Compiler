#include "il2mips.hpp"

void IL2MIPS::fend(Instr instr, MIPSContext &context) 
{
    ret(context);
    context.popFrame();
    context.addRawInstr(Instr(""));
}