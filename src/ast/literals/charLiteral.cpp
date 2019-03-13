#include "charLiteral.hpp"

CharLiteral::CharLiteral(int value){
	_value = value; 
}
void CharLiteral::printC(std::ostream &os) const
{
	os << "\'" << _value << "\'";
}