#include "il2mips.hpp"

void IL2MIPS::orM(Instr instr, MIPSContext &context) 
{
    context.addInstr(instr);
}