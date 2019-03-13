#include "integerLiteral.hpp"

IntegerLiteral::IntegerLiteral(int _value){
	value = _value;
}
void IntegerLiteral::printC(std::ostream &os) const
{
	os << value;
}