#include "il2mips.hpp"

void IL2MIPS::init(Instr instr, MIPSContext &context) 
{
    context.loadAddress(instr.input1, instr.dest);
}