#include "il2mips.hpp"

void IL2MIPS::li(Instr instr, MIPSContext &context) 
{
    context.addInstr(instr);
}