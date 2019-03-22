#include "il2mips.hpp"

void IL2MIPS::eq(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("xor", "$t0", instr.input1, instr.input2));
    context.addInstr(Instr("sltiu", instr.dest, "$t0", "1"));
}