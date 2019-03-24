#include "il2mips.hpp"

void IL2MIPS::bez(Instr instr, MIPSContext &context) 
{
    context.addBranchInstr(Instr("beq", instr.input1, "$0", instr.dest));
}