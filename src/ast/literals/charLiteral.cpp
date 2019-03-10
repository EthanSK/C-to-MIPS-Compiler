#include "charLiteral.hpp"

void CharLiteral::printC(std::ostream &os) const
{
	os << "\'" << value << "\'";
}