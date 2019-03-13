#include "arrayType.hpp"

void ArrayType::printC(std::ostream &os) const
{
    os << typeToString() << " " << name << "[" << size << "]";
} 