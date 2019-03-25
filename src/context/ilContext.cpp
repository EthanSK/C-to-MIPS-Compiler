#include "ilContext.hpp"
#include "statement.hpp"
#include "rvalue.hpp"
#include "utils.hpp"
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

void ILContext::compileInput(StatementPtr input, std::vector<Instr> &instrs, std::string destReg)
{
    RValuePtr rvalue = Utils::tryCast<RValue>(input, "input must be an rvalue to be compiled");
    if (rvalue->isConstant())
    {
        int result = rvalue->evalConst();
        instrs.push_back(Instr("li", destReg, std::to_string(result)));
    }
    else
    {
        input->generateIL(instrs, *this, destReg);
    }
}

void ILContext::pushLoopLabels(std::string startLabel, std::string endLabel)
{
    _loopLabelStack.push_back(std::make_tuple(startLabel, endLabel));
}

void ILContext::popLoopLabels()
{
    _loopLabelStack.pop_back();
}

std::tuple<std::string, std::string> ILContext::getLastLoopLabel()
{
    return _loopLabelStack.back();
}
