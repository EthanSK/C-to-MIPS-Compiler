#include "il2mips.hpp"

void IL2MIPS::gt(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("slt", instr.dest, instr.input1, instr.input2));
    context.addInstr(Instr("sltiu", instr.dest, "$t0", "1"));
}