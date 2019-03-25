#include "il2mips.hpp"

void IL2MIPS::loc(Instr instr, MIPSContext &context) 
{
    context.loadAddress(instr.dest, instr.input1);
}