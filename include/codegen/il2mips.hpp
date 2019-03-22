#ifndef il2mips_hpp
#define il2mips_hpp

#include "instr.hpp"
#include "context.hpp"

class IL2MIPS //one IL may map to many MIPS
{
public:
    static void convertToMIPS(std::vector<Instr> &instrs, std::vector<Instr> &mipsInstrs);
    static void convertToMIPS(std::vector<Instr> &instrs, MIPSContext &context, std::vector<Instr> &mipsInstrs);
    
private:
    static void convertInstr(Instr &instr, MIPSContext &context, std::vector<Instr> &mipsInstrs);

    static void li(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs);
    static void scu(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs);
    static void scd(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs);
    static void decl(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs);
    static void fdef(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs);
    static void fcall(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs);
    static void fend(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs);
    static void retv(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs);
    static void mov(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs);
    static void eq(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs);
    static void ne(Instr instr, MIPSContext &context, std::vector<Instr> &mipsInstrs);
};

#endif