#include "binaryBitwiseXorAssignment.hpp"

void BinaryBitwiseXorAssignment::printC(std::ostream &os) const
{
	os << getLeft();
	os << " ^= ";
	os << getRight();
}

void BinaryBitwiseXorAssignment::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	getLeft()->generatePython(os, context, scopeDepth);
	os << " ^= ";
	getRight()->generatePython(os, context, scopeDepth);
}

void BinaryBitwiseXorAssignment::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
	//ASSIGNMENT VERSION
	std::string leftReg = context.makeName("xor.eq_l");
	std::string rightReg = context.makeName("xor.eq_r");
	getLeft()->generateIL(instrs, context, leftReg);
	getRight()->generateIL(instrs, context, rightReg);
	instrs.push_back(ILinstr("xor.eq", destReg, leftReg, rightReg));
}