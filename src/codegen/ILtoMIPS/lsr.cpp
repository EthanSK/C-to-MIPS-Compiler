#include "il2mips.hpp"

void IL2MIPS::lsr(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("srl", instr.dest, instr.input1, instr.input2), instr.label);
}