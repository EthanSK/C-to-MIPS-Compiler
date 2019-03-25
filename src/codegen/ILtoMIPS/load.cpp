#include "il2mips.hpp"

void IL2MIPS::load(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("mov", "$t0", instr.input1), instr.label);
    context.addRawInstr(Instr("lw", instr.dest, instr.input2 + "($t0)"));
}