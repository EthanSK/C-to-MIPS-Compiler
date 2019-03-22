#include "il2mips.hpp"

void IL2MIPS::scu(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs) 
{
    context.getAllocator().pushFrame();
}