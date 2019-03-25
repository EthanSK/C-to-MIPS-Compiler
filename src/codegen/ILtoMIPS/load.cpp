#include "il2mips.hpp"

void IL2MIPS::load(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("move", "$t0", instr.input1), instr.label);
    context.addRawInstr(Instr("lw", "$t0", instr.input2 + "($t0)"));
    context.addInstr(Instr("move", instr.dest, "$t0"));
}