#include "binaryLeftShiftAssignment.hpp"

void BinaryLeftShiftAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " <<= ";
	os << getRight();
}

void BinaryLeftShiftAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " <<= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryLeftShiftAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	std::string innerLeftReg = "temp_reg_left";
	std::string innerRightReg = "temp_reg_right";
	getLeft()->generateIL(instrs, context, innerLeftReg);
	getRight()->generateIL(instrs, context, innerRightReg);
	ILinstr instr("leftShiftAssignment", destReg, innerLeftReg, innerRightReg); 
	instrs.push_back(instr);
}