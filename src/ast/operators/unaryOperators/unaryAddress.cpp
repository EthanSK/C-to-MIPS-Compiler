#include "unaryAddress.hpp"
#include "utils.hpp"
#include "identifier.hpp"

void UnaryAddress::printC(std::ostream &os) const
{
	os << "&(" << getOperand() << ")";
}

void UnaryAddress::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    IdentifierPtr identifier = Utils::tryCast<Identifier>(getOperand(), "address of operator only works on identifiers");
	instrs.push_back(Instr("loc", destReg, identifier->toString()));
}

bool UnaryAddress::isConstant() const { return false; }
int UnaryAddress::evalConst() const { throw "cannot statically evaluate an address"; }