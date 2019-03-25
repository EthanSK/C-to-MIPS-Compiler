#include "identifier.hpp"

Identifier::Identifier(std::string name)
{
	_name = name;
}

std::string Identifier::getName() const { return _name; }

void Identifier::printC(std::ostream &os) const
{
	os << _name;
}

void Identifier::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
	os << _name;
}

void Identifier::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
	instrs.push_back(Instr("mov", destReg, _name));
}

void Identifier::generateLValueStoreIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const
{
	instrs.push_back(Instr("mov", _name, inputReg));
}

void Identifier::generateLValueLocateIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const
{
	instrs.push_back(Instr("loc", inputReg, _name));
}

bool Identifier::isConstant() const { return false; }
int Identifier::evalConst() const { throw "cannot statically evaluate an identifier"; }