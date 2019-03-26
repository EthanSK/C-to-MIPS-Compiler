#include "il2mips.hpp"

void IL2MIPS::div(Instr instr, MIPSContext &context) 
{
    //using addBranchInstr because destreg is actually an input. just happens to work for branches too so using same func
    context.addBranchInstr(Instr("div", instr.input1, instr.input2), instr.label); //div puts quotient in LO and remainder in HI
    context.addInstr(Instr("mflo", instr.dest));
} 