#include "MIPSinstrI.hpp"

std::string MIPSinstrI::toString() const
{
    return opcode + " " + source1_or_dest + " " + source2 + " " + immediate;
}