#include "il2mips.hpp"

void IL2MIPS::sub(Instr instr, MIPSContext &context) 
{
    context.addInstr(instr);
}