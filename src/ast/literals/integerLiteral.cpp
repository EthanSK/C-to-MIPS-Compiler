#include "integerLiteral.hpp"

IntegerLiteral::IntegerLiteral(int value){
	_value = value;
}
void IntegerLiteral::printC(std::ostream &os) const
{
	os << _value;
}