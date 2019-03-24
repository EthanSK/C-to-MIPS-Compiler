#include "mipsContext.hpp"
#include <sstream>
#include <algorithm>

std::vector<Instr> MIPSContext::dumpInstrs() const
{
    return _instrs;
}

void MIPSContext::pushFrame()
{
    _allocator.pushFrame();
    _instrs.push_back(Instr("#scu"));
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
    if (isGlobalScope())
    {
        _globals.insert(allocation.name);
        _instrs.push_back(Instr(".globl", allocation.name));
        _instrs.push_back(Instr(".size", allocation.name, std::to_string(allocation.size)));
        _instrs.push_back(Instr::makeLabel(allocation.name));
    }
    else
    {
        int offset = -allocation.size;
        _allocator.allocate(allocation);
        
        std::vector<Instr>::iterator inserter = _instrs.end();
        while (inserter != _instrs.begin() && (inserter - 1)->opcode != "#scu")
        {
            inserter--;
            if (std::find(inserter->extraData.begin(), inserter->extraData.end(), "#raw") == inserter->extraData.end())
            {
                inserter->input1 = correctStackReference(inserter->input1, offset);
            }
        }

        if (inserter != _instrs.end() && inserter->opcode == "addi" && inserter->dest == "$sp" && inserter->input1 == "$sp")
        {
            inserter->input2 = std::to_string(std::stoi(inserter->input2) + offset);
        }
        else
        {
            Instr allocInstr("addi", "$sp", "$sp", std::to_string(offset));
            _instrs.insert(inserter, allocInstr);
        }
    }
}

std::string MIPSContext::correctStackReference(std::string ref, int offset) const
{
    if (!std::regex_match(ref, _isStackRef)) { return ref; }

    std::string offsetStr = ref.substr(0, ref.find("("));
    int originalOffset = std::stoi(offsetStr);
    int correctedOffset = originalOffset - offset;
    return std::to_string(correctedOffset) + "($sp)";
}

void MIPSContext::addRootInstr(Instr instr)
{
    _instrs.insert(_instrs.begin(), instr);
}

void MIPSContext::addRawInstr(Instr instr)
{
    _instrs.push_back(instr);
}

void MIPSContext::addInstr(Instr instr) { addInstr(instr, instr.label); }
void MIPSContext::addInstr(Instr instr, std::string label)
{
    std::string destName = instr.dest;
    if (destName == "_root") { return; }

    bool reqStore = requiresStack(instr.dest);
    if (reqStore)
    {
        if (!isAllocated(instr.dest))
        {
            Allocation allocation(4, instr.dest);
            alloc(allocation);
        }
    }

    instr.label = label;
    instr.dest = reqStore ? "$t1" : destName;
    instr.input1 = loadInput(instr.input1, "$t2");
    instr.input2 = loadInput(instr.input2, "$t3");
    _instrs.push_back(instr);

    if (reqStore)
    {
        _instrs.push_back(Instr("sw", "$t1", getAllocationLocation(destName)));
    }
}

void MIPSContext::addBranchInstr(Instr instr) { addBranchInstr(instr, instr.label); }
void MIPSContext::addBranchInstr(Instr instr, std::string label)
{
    instr.label = label;
    instr.dest = loadInput(instr.dest, "$t1");
    instr.input1 = loadInput(instr.input1, "$t2");
    instr.input2 = loadInput(instr.input2, "$t3");
    _instrs.push_back(instr);
    _instrs.push_back(Instr("nop"));
}

bool MIPSContext::requiresStack(std::string reg) const
{
    if (reg.size() == 0) { return false; }
    if (reg.find('$') != std::string::npos) { return false; }
    if (std::regex_match(reg, _isNumber)) { return false; }
    return true;
}

std::string MIPSContext::loadInput(std::string regName, std::string mipsReg)
{
    if (!requiresStack(regName)) { return regName; }
    if (!isAllocated(regName)) { return regName; }

    _instrs.push_back(Instr("lw", mipsReg, getAllocationLocation(regName)));
    _instrs.push_back(Instr("nop"));
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

bool MIPSContext::isGlobalScope() const
{
    return _allocator.frameCount() == 0;
}