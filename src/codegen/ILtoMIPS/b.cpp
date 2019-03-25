#include "il2mips.hpp"

void IL2MIPS::b(Instr instr, MIPSContext &context) 
{
    context.addBranchInstr(Instr("j", instr.dest, "", "", instr.extraData), instr.label);
}