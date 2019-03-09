#include "stringLiteral.hpp"

void StringLiteral::printCode(std::ostream &os) const
{
	os << "\"" << value << "\"";
}