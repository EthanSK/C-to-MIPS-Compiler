#include "il2mips.hpp"

void IL2MIPS::lt(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("slt", instr.dest, instr.input1, instr.input2), instr.label);
}