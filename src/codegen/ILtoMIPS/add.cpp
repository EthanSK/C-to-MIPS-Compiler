#include "il2mips.hpp"

void IL2MIPS::add(Instr instr, MIPSContext &context) 
{
    context.addInstr(instr);
}