#include "charLiteral.hpp"

CharLiteral::CharLiteral(int _value){
	value = _value; 
}
void CharLiteral::printC(std::ostream &os) const
{
	os << "\'" << value << "\'";
}