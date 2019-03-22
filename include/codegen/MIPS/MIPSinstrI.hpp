#ifndef mipsinstrI_hpp
#define mipsinstrI_hpp

#include "MIPSinstr.hpp"

struct MIPSinstrI : public MIPSinstr //I type
{
    std::string opcode;
    std::string source1_or_dest;
    std::string source2;
    std::string immediate; //keep as string as more flexible

    MIPSinstrI(std::string opcode, std::string source1_or_dest, std::string source2, std::string immediate) : opcode(opcode), source1_or_dest(source1_or_dest), source2(source2), immediate(immediate){};
    
    std::string toString() const override;
};

#endif