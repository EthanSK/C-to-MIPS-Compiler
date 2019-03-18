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