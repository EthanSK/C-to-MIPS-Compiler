#include "unarySizeof.hpp"
#include "identifier.hpp"
#include "utils.hpp"

void UnarySizeof::printC(std::ostream &os) const
{
	os << "sizeof(" << getOperand() << ")";
}

void UnarySizeof::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    try
    {
        IdentifierPtr id = Utils::tryCast<Identifier>(getOperand(), "");
        instrs.push_back(Instr("size", destReg, id->getName()));
    }
    catch(std::string)
    {
        getOperand()->generateIL(instrs, context, "_root");
        instrs.push_back(Instr("li", destReg, "4"));
    }
    
}

bool UnarySizeof::isConstant() const { return false; }
int UnarySizeof::evalConst() const { throw "cannot statically evaluate a sizeof"; }