#include "ilContext.hpp"
#include "statement.hpp"
#include <sstream>
#include <ios>

std::string ILContext::makeName(std::string name)
{
    std::stringstream ss;
    int nameCount = _registeredNames[name]++;
    ss << "0x" << std::hex << nameCount << std::dec << "_" << name;
    return ss.str();
}

std::string ILContext::makeLabelName(std::string name)
{
    return "l" + makeName(name);
}

void ILContext::compileInput(StatementPtr input, std::vector<Instr> &instrs, std::string destReg) const
{
    //RValuePtr 
}