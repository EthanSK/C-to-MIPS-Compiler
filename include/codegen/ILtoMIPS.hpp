#ifndef mipsinstrJ_hpp
#define mipsinstrJ_hpp

#include "MIPSinstr.hpp"
#include "ILinstr.hpp"
#include "context.hpp"

class ILtoMIPS //one IL may map to many MIPS
{
public:
    static void convertToMIPS(std::vector<ILinstr> &ilInstrs, MIPSContext &context, std::vector<MIPSinstr> &mipsInstrs);
    
private:
    static void convertInstr(ILinstr &instr, MIPSContext &context, std::vector<MIPSinstr> &mipsInstrs);

    static void fdef(ILinstr instr, MIPSContext &context, std::vector<MIPSinstr> &mipsInstr);
    static void fcall(ILinstr instr, MIPSContext &context, std::vector<MIPSinstr> &mipsInstr);
    static void fend(ILinstr instr, MIPSContext &context, std::vector<MIPSinstr> &mipsInstr);
};

#endif