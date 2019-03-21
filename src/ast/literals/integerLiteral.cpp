#include "integerLiteral.hpp"
#include <string>

IntegerLiteral::IntegerLiteral(int value){
	_value = value;
}
void IntegerLiteral::printC(std::ostream &os) const
{
	os << _value;
}

void IntegerLiteral::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << _value;
}

void IntegerLiteral::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    instrs.push_back(ILinstr("li", destReg, std::to_string(_value)));
} 