#include "il2mips.hpp"

void IL2MIPS::gte(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("slt", instr.dest, instr.input2, instr.input1), instr.label);
}