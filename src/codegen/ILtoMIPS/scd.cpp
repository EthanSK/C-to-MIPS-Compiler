#include "il2mips.hpp"

void IL2MIPS::scd(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs) 
{
    context.popFrame(mipsInstrs);
}