#include "il2mips.hpp"

void IL2MIPS::inc(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("addi", instr.dest, instr.dest, "1"), instr.label);
}