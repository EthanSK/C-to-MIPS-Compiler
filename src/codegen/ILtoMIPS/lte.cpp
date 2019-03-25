#include "il2mips.hpp"

void IL2MIPS::lte(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("addi", "$t0", instr.input2, "1"));
    context.addInstr(Instr("slt", instr.dest, instr.input1, "$t0"), instr.label);
    context.addInstr(Instr("sltiu", instr.dest, "$t0", "1"));
}