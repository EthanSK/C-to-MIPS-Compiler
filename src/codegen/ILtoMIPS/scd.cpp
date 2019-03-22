#include "ILtoMIPS.hpp"

void ILtoMIPS::scd(ILinstr instr, MIPSContext &context, std::vector<MIPSinstr> &mipsInstr) 
{
    context.getAllocator().popFrame();
}