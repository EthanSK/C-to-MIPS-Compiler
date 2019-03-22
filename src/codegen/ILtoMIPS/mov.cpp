#include "il2mips.hpp"

void IL2MIPS::mov(Instr instr, MIPSContext &context) 
{
    context.addInstr(instr);
}