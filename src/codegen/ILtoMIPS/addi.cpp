#include "il2mips.hpp"

void IL2MIPS::addi(Instr instr, MIPSContext &context) 
{
    context.addInstr(instr);
}