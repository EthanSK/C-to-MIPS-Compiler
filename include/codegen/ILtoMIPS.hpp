#ifndef mipsinstrJ_hpp
#define mipsinstrJ_hpp

#include "MIPSinstr.hpp"
#include "ILinstr.hpp"

class ILtoMIPS //one IL may map to many MIPS
{
    static void convertToMIPS(std::vector<ILinstr> &ilInstrs, std::vector<MIPSinstr> &mipsInstr); //might need context?

    static void fdef(ILinstr instr, std::vector<MIPSinstr> &mipsInstr);
    static void fcall(ILinstr instr, std::vector<MIPSinstr> &mipsInstr);
    static void fend(ILinstr instr, std::vector<MIPSinstr> &mipsInstr);
};

#endif