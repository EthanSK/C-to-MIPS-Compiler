#include "il2mips.hpp"

void IL2MIPS::neg(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("not", instr.dest, instr.input1), instr.label);
}