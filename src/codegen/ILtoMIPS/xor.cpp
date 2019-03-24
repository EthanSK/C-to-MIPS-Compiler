#include "il2mips.hpp"

void IL2MIPS::xorM(Instr instr, MIPSContext &context) 
{
    context.addInstr(instr);
}