#include "il2mips.hpp"

void IL2MIPS::andM(Instr instr, MIPSContext &context) 
{
    context.addInstr(instr);
}