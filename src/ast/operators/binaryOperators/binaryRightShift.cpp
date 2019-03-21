#include "binaryRightShift.hpp"

void BinaryRightShift::printC(std::ostream &os) const
{
	os << "(";
	os << getLeft();
	os << " >> ";
	os << getRight();
	os << ")";
}

void BinaryRightShift::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << "(";
	getLeft()->generatePython(os, context, scopeDepth);
	os << " >> ";
	getRight()->generatePython(os, context, scopeDepth);
	os << ")";
}

void BinaryRightShift::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string innerLeftReg = "temp_reg_left";
	std::string innerRightReg = "temp_reg_right";
	getLeft()->generateIL(instrs, context, innerLeftReg);
	getRight()->generateIL(instrs, context, innerRightReg);
	ILinstr instr("rightShift", destReg, innerLeftReg, innerRightReg); 
	instrs.push_back(instr);
}