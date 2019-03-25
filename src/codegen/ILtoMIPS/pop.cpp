#include "il2mips.hpp"

void IL2MIPS::pop(Instr instr, MIPSContext &context) 
{
    int frameSize = context.getAllocator().topFrame().getFrameSize();
    context.addRawInstr(Instr("addi", "$sp", "$sp", std::to_string(frameSize), {"#pop"}));
}