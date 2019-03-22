#ifndef mipsinstrR_hpp
#define mipsinstrR_hpp

#include "MIPSinstr.hpp"

struct MIPSinstrR : public MIPSinstr //R type
{
    std::string opcode;  //eg add
    std::string dest;    //eg $1
    std::string source1; //eg $5
    std::string source2; //eg $6

    MIPSinstrR(std::string opcode, std::string dest, std::string source1, std::string source2) : opcode(opcode), dest(dest), source1(source1), source2(source2){};

    std::string toString() const override;
};

#endif