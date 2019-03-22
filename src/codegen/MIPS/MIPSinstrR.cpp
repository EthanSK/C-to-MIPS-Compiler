#include "MIPSinstrR.hpp"

std::string MIPSinstrR::toString() const
{
    return opcode + " " + dest + " " + source1 + " " + source2;
}