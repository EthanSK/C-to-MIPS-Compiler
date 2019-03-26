#include "il2mips.hpp"

void IL2MIPS::bgz(Instr instr, MIPSContext &context) 
{
    context.addBranchInstr(Instr("bgtz", instr.input1, instr.dest), instr.label);
}