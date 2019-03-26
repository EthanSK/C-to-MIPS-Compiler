#include "il2mips.hpp"

void IL2MIPS::size(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("li", instr.dest, "4"), instr.label);
}