#include "il2mips.hpp"

void IL2MIPS::retv(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("mov", "$v0", instr.dest));
    ret(context);
}