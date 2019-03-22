#include "context.hpp"
#include <sstream>
#include <ios>

void PythonContext::indentStream(std::ostream& os, int scopeDepth) const
{
    os << std::endl;
    for (int i = 0; i < scopeDepth * PY_INDENT_SIZE; i++)
    {
        os << " ";
    }
}

void PythonContext::dumpGlobals(std::ostream& os, int scopeDepth) const
{
    if (_globalIdentifiers.size() > 0)
    {
        indentStream(os, scopeDepth);
        os << "global ";
        for (int i = 0; i < _globalIdentifiers.size(); ++i)
        {
            if (i > 0) { os << ", "; }
            os << _globalIdentifiers[i];
        }
    }
}

void PythonContext::registerGlobal(std::string identifier)
{
    _globalIdentifiers.push_back(identifier);
}

std::string ILContext::makeName(std::string name)
{
    std::stringstream ss;
    int nameCount = _registeredNames[name]++;
    ss << "0x" << std::hex << nameCount << std::dec << "_" << name;
    return ss.str();
}

Allocator& MIPSContext::getAllocator()
{
    return _allocator;
}

void MIPSContext::popFrame(std::vector<Instr> &mipsInstrs)
{
    int stackSize = _allocator.stackSize();
    _allocator.popFrame();
    int frameSize = stackSize - _allocator.stackSize();
    if (frameSize > 0)
    {
        mipsInstrs.push_back(Instr("addi", "$sp", "$sp", std::to_string(frameSize)));
    }
}

void MIPSContext::alloc(Allocation allocation, std::vector<Instr> &mipsInstrs)
{
    _allocator.allocate(allocation);
    mipsInstrs.push_back(Instr("subi", "$sp", "$sp", std::to_string(allocation.size)));
}