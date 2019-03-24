#include "il2mips.hpp"

void IL2MIPS::lte(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("slt", instr.dest, instr.input2, instr.input1));
    context.addInstr(Instr("sltiu", instr.dest, "$t0", "1"));
}