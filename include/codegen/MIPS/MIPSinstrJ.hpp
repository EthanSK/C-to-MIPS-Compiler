#ifndef mipsinstrJ_hpp
#define mipsinstrJ_hpp

#include "MIPSinstr.hpp"


struct MIPSinstrJ : public MIPSinstr //J type
{
    std::string opcode;
    std::string target; //can be label or address offset?

    std::string toString() const override;
}; 

#endif