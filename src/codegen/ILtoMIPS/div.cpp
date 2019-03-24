#include "il2mips.hpp"

void IL2MIPS::div(Instr instr, MIPSContext &context) 
{
    context.addInstr(Instr("div", instr.input1, instr.input2), instr.label); //div puts quotient in LO and remainder in HI
    context.addInstr(Instr("mflo", instr.dest));
} 