#include "il2mips.hpp"

void IL2MIPS::store(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("move", "$t0", instr.input1), instr.label);
    context.addInstr(Instr("move", "$t1", instr.dest), instr.label);
    context.addRawInstr(Instr("sw", "$t1", instr.input2 + "($t0)"));
}