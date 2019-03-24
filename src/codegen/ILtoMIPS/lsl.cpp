#include "il2mips.hpp"

void IL2MIPS::lsl(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("sll", instr.dest, instr.input1, instr.input2), instr.label);
}