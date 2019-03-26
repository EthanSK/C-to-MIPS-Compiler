#include "il2mips.hpp"

void IL2MIPS::size(Instr instr, MIPSContext &context) 
{
    int allocSize = context.getAllocationSize(instr.input1);
    context.addInstr(Instr("li", instr.dest, std::to_string(allocSize)), instr.label);
}