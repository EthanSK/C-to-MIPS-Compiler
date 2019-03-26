#include "il2mips.hpp"

void IL2MIPS::beq(Instr instr, MIPSContext &context) 
{
    context.addBranchInstr(Instr("beq", instr.input1, instr.input2, instr.dest), instr.label);
}