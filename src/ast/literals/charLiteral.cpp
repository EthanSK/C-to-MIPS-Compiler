#include "charLiteral.hpp"

CharLiteral::CharLiteral(int value){
	value = value; 
}
int CharLiteral::getValue() const
{
	return value;
}
void CharLiteral::printC(std::ostream &os) const
{
	os << "\'" << value << "\'";
}