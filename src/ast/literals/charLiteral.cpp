#include "charLiteral.hpp"

CharLiteral::CharLiteral(int _value){
	value = _value; 
}
int CharLiteral::getValue() const
{
	return value;
}
void CharLiteral::printC(std::ostream &os) const
{
	os << "\'" << value << "\'";
}