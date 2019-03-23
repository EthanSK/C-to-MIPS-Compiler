#include "il2mips.hpp"

void IL2MIPS::mul(Instr instr, MIPSContext &context) 
{
    //supports int multiplication for now
    context.addInstr(instr); //mul not mult coz C only cares about 32 lsbs of result
}