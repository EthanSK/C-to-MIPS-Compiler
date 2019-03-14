#include "charLiteral.hpp"

CharLiteral::CharLiteral(int value){
	_value = value; 
}

void CharLiteral::printC(std::ostream &os) const
{
	os << "\'" << _value << "\'";
}

void CharLiteral::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "'" << _value << "'";
}