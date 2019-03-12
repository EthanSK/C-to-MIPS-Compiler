#include "integerLiteral.hpp"

IntegerLiteral::IntegerLiteral(int _value){
	value = _value;
}

int IntegerLiteral::getValue() const
{
	return value;
}
void IntegerLiteral::printC(std::ostream &os) const
{
	os << value;
}