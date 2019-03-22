#include "MIPSinstrJ.hpp"

std::string MIPSinstrJ::toString() const
{
    return opcode + " " + target;
}