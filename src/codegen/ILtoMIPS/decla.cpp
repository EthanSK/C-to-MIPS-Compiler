#include "il2mips.hpp"

void IL2MIPS::decla(Instr instr, MIPSContext &context) 
{
    Allocation allocation(std::stoi(instr.input1), instr.dest);
    context.allocArray(allocation);
}