#include "arrayElementReference.hpp"

ArrayElementReference::ArrayElementReference(StatementPtr arr, StatementPtr index)
{
    branches.push_back(arr);
    branches.push_back(index);
}

StatementPtr ArrayElementReference::getArr() const
{
    return branches[0];
}

StatementPtr ArrayElementReference::getIndex() const
{
    return branches[1];
}

void ArrayElementReference::printC(std::ostream &os) const
{
    os << getArr() << "[" << getIndex() << "]";
}


void ArrayElementReference::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    std::string offsetName = context.makeName("arr_offset");
    std::string locName = context.makeName("arr_loc");

    getArr()->generateIL(instrs, context, locName);
    context.compileInput(getIndex(), instrs, offsetName);
    instrs.push_back(Instr("lsl", "$t0", offsetName, "2"));
    instrs.push_back(Instr("add", "$t0", "$t0", locName));
	instrs.push_back(Instr("load", destReg, "$t0", "0"));
}

void ArrayElementReference::generateLValueStoreIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const
{
    std::string offsetName = context.makeName("arr_offset");
    std::string locName = context.makeName("arr_loc");

    getArr()->generateIL(instrs, context, locName);
    context.compileInput(getIndex(), instrs, offsetName);
    instrs.push_back(Instr("lsl", "$t0", offsetName, "2"));
    instrs.push_back(Instr("add", "$t0", "$t0", locName));
	instrs.push_back(Instr("store", inputReg, "$t0", "0"));
}

void ArrayElementReference::generateLValueLocateIL(std::vector<Instr> &instrs, ILContext &context, std::string inputReg) const
{
    throw "array value locate not yet supported";
}

bool ArrayElementReference::isConstant() const { return false; }
int ArrayElementReference::evalConst() const { throw "cannot statically evaluate an identifier"; }