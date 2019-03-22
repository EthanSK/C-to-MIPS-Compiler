#include "ILtoMIPS.hpp"

void ILtoMIPS::scu(ILinstr instr, MIPSContext &context, std::vector<MIPSinstr> &mipsInstr) 
{
    context.getAllocator().pushFrame();
}