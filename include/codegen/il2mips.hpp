#ifndef il2mips_hpp
#define il2mips_hpp

#include "instr.hpp"
#include "context.hpp"

class IL2MIPS //one IL may map to many MIPS
{
public:
    static std::vector<Instr> convertToMIPS(std::vector<Instr> &instrs);
    
private:
    static void convertInstr(Instr &instr, MIPSContext &context);

    static void li(Instr instr, MIPSContext &context);
    static void scu(Instr instr, MIPSContext &context);
    static void scd(Instr instr, MIPSContext &context);
    static void decl(Instr instr, MIPSContext &context);
    static void fdef(Instr instr, MIPSContext &context);
    static void fcall(Instr instr, MIPSContext &context);
    static void fend(Instr instr, MIPSContext &context);
    static void retv(Instr instr, MIPSContext &context);
    static void mov(Instr instr, MIPSContext &context);
    static void eq(Instr instr, MIPSContext &context);
    static void ne(Instr instr, MIPSContext &context);

    static void ret(MIPSContext &context);
};

#endif