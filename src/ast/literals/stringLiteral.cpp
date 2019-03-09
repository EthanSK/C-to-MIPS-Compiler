#include "stringLiteral.hpp"

void StringLiteral::printC(std::ostream &os) const
{
	os << "\"" << value << "\"";
}