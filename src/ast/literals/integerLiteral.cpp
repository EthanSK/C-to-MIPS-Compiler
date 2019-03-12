#include "integerLiteral.hpp"

IntegerLiteral::IntegerLiteral(int value){
	value = value;
}

int IntegerLiteral::getValue() const
{
	return value;
}
void IntegerLiteral::printC(std::ostream &os) const
{
	os << value;
}