#include "context.hpp"
#include <sstream>
#include <ios>

void PythonContext::indentStream(std::ostream &os, int scopeDepth) const
{
    os << std::endl;
    for (int i = 0; i < scopeDepth * PY_INDENT_SIZE; i++)
    {
        os << " ";
    }
}

void PythonContext::dumpGlobals(std::ostream &os, int scopeDepth) const
{
    if (_globalIdentifiers.size() > 0)
    {
        indentStream(os, scopeDepth);
        os << "global ";
        for (int i = 0; i < _globalIdentifiers.size(); ++i)
        {
            if (i > 0)
            {
                os << ", ";
            }
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

std::vector<Instr> MIPSContext::dumpInstrs() const
{
    return _instrs;
}

void MIPSContext::pushFrame()
{
    _allocator.pushFrame();
}

void MIPSContext::popFrame()
{
    int stackSize = _allocator.stackSize();
    _allocator.popFrame();
    int frameSize = stackSize - _allocator.stackSize();
    if (frameSize > 0)
    {
        _instrs.push_back(Instr("addi", "$sp", "$sp", std::to_string(frameSize)));
    }
}

void MIPSContext::alloc(Allocation allocation)
{
    if (_allocator.frameCount() > 0)
    {
        _allocator.allocate(allocation);
        _instrs.push_back(Instr("addi", "$sp", "$sp", "-" + std::to_string(allocation.size)));
    }
    else
    {
        _globals.insert(allocation.name);
        _instrs.push_back(Instr::makeLabel(allocation.name));
    }
}

void MIPSContext::addInstr(Instr instr)
{
    std::string destName = instr.dest;
    if (destName == "_root")
    {
        return;
    }

    bool reqStore = requiresStack(instr.dest);
    if (reqStore)
    {
        if (!isAllocated(instr.dest))
        {
            Allocation allocation(4, instr.dest);
            alloc(allocation);
        }
    }

    instr.dest = reqStore ? "$t1" : destName;
    instr.input1 = loadInput(instr.input1, "$t2");
    instr.input2 = loadInput(instr.input2, "$t3");
    _instrs.push_back(instr);

    if (reqStore)
    {
        _instrs.push_back(Instr("sw", "$t1", getAllocationLocation(destName)));
    }
}

bool MIPSContext::requiresStack(std::string reg) const
{
    if (reg.size() == 0)
    {
        return false;
    }
    if (reg.find('$') != std::string::npos)
    {
        return false;
    }
    if (std::regex_match(reg, _isNumber))
    {
        return false;
    }
    return true;
}

std::string MIPSContext::loadInput(std::string regName, std::string mipsReg)
{
    if (!requiresStack(regName))
    {
        return regName;
    }

    _instrs.push_back(Instr("lw", mipsReg, getAllocationLocation(regName)));
    return mipsReg;
}

int MIPSContext::stackSize() const
{
    return _allocator.stackSize();
}

std::string MIPSContext::getAllocationLocation(std::string regName) const
{
    if (_globals.count(regName) == 0)
    {
        int regLocation = _allocator.getAllocationOffset(regName);
        return std::to_string(regLocation) + "($sp)";
    }
    else
    {
        return regName + "($gp)";
    }
}

bool MIPSContext::isAllocated(std::string reg) const
{
    return _globals.count(reg) > 0 || _allocator.isAllocated(reg);
}