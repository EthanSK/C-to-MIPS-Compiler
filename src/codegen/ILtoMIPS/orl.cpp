#include "il2mips.hpp"

void IL2MIPS::orl(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("or", "$t0", instr.input1, instr.input2), instr.label);
    context.addInstr(Instr("sltu", instr.dest, "$0", "$t0"), instr.label);
}