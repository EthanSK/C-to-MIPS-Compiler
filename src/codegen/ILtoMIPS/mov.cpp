#include "il2mips.hpp"

void IL2MIPS::mov(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("move", instr.dest, instr.input1), instr.label);
}