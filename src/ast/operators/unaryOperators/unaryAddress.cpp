#include "unaryAddress.hpp"
#include "utils.hpp"
#include "lvalue.hpp"

void UnaryAddress::printC(std::ostream &os) const
{
	os << "&(" << getOperand() << ")";
}

void UnaryAddress::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    LValuePtr lvalue = Utils::tryCast<LValue>(getOperand(), "operand of address of operator must be an lvalue");
	lvalue->generateLValueLocateIL(instrs, context, destReg);
}

void UnaryAddress::generateLValueStoreIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const
{
	throw "address operator as an lvalue can only be used for locating";
}

void UnaryAddress::generateLValueLocateIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const
{
	LValuePtr lvalue = Utils::tryCast<LValue>(getOperand(), "operand of address of operator must be an lvalue");
	lvalue->generateLValueLocateIL(instrs, context, inputReg);
}

bool UnaryAddress::isConstant() const { return false; }
int UnaryAddress::evalConst() const { throw "cannot statically evaluate an address"; }