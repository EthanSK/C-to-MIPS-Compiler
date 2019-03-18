#include "charLiteral.hpp"

CharLiteral::CharLiteral(int value){
	_value = value; 
}

std::string CharLiteral::getEscapedChar() const
{
	if (_value == '\\') { return "\\\\"; }
    else if (_value == '\n') { return "\\n"; }
    else if (_value == '\r') { return "\\r"; }
    else if (_value == '\t') { return "\\t"; }
    else if (_value == '\0') { return "\\0"; }
    else if (_value == '\"') { return "\\\""; }
    else { return std::string(1, (char)_value); }
}

void CharLiteral::printC(std::ostream &os) const
{
	os << "\'" << getEscapedChar() << "\'";
}

void CharLiteral::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "'" << getEscapedChar() << "'";
}