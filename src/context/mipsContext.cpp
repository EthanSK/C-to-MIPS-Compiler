#include "mipsContext.hpp"
#include "utils.hpp"
#include <sstream>
#include <algorithm>

std::vector<Instr> MIPSContext::dumpInstrs() const
{
    std::vector<Instr> finalInstrs = _instrs;
    //return _instrs;
    for (int i = finalInstrs.size() - 1; i >= 0; --i)
    {
        if (finalInstrs[i].opcode == "move" && finalInstrs[i].dest == finalInstrs[i].input1) { finalInstrs.erase(finalInstrs.begin() + i); continue; }
        if (finalInstrs[i].opcode == "move" && finalInstrs[i].dest == "$0") { finalInstrs.erase(finalInstrs.begin() + i); continue; }
        if (finalInstrs[i].opcode == "#scu" || finalInstrs[i].opcode == "#scd") { finalInstrs.erase(finalInstrs.begin() + i); continue; }
        if (finalInstrs[i].opcode == "addi" && finalInstrs[i].dest == finalInstrs[i].input1 && finalInstrs[i].dest == "$sp")
        {
            if (finalInstrs[i].input2 == "0" ) { finalInstrs.erase(finalInstrs.begin() + i); continue; }
        }

        if (i > 0 && finalInstrs[i].opcode == "sw" && finalInstrs[i - 1].opcode == "move")
        {
            if (finalInstrs[i].dest == finalInstrs[i - 1].dest)
            {
                finalInstrs[i].dest = finalInstrs[i - 1].input1;
                finalInstrs.erase(finalInstrs.begin() + i - 1);
                i--;
                continue;
            }
        }

        if (i > 1 && finalInstrs[i].opcode == "move" && finalInstrs[i - 2].opcode == "lw")
        {
            if (finalInstrs[i].input1 == finalInstrs[i - 2].dest)
            {
                finalInstrs[i - 2].dest = finalInstrs[i].dest;
                finalInstrs.erase(finalInstrs.begin() + i);
                i -= 2;
                continue;
            }
        }

        if (i > 0 && finalInstrs[i].opcode == "move" && finalInstrs[i - 1].opcode == "li")
        {
            if (finalInstrs[i].input1 == finalInstrs[i - 1].dest)
            {
                finalInstrs[i - 1].dest = finalInstrs[i].dest;
                finalInstrs.erase(finalInstrs.begin() + i);
                i--;
                continue;
            }
        }

        finalInstrs[i].extraData.clear();
    }

    return finalInstrs;
}

void MIPSContext::pushFrame()
{
    _allocator.pushFrame();
    _instrs.push_back(Instr("#scu"));
}

void MIPSContext::popFrame()
{
    int frameSize = _allocator.topFrame().getFrameSize();
    _allocator.popFrame();
    _instrs.push_back(Instr("#scd"));
    _instrs.push_back(Instr("addi", "$sp", "$sp", std::to_string(frameSize)));
}

void MIPSContext::alloc(Allocation allocation)
{
    if (isGlobalScope())
    {
        _globals.insert(allocation.name);
        _instrs.push_back(Instr(".data"));
        _instrs.push_back(Instr(".globl", allocation.name));
        _instrs.push_back(Instr(".size", allocation.name, std::to_string(allocation.size)));
        _instrs.push_back(Instr::makeLabel(allocation.name));
        _instrs.push_back(Instr(".word", "0"));
    }
    else
    {
        int offset = -allocation.size;
        _allocator.allocate(allocation);
        
        int remainingHits = 1;
        std::vector<Instr>::iterator inserter = _instrs.end();
        while (inserter != _instrs.begin() && remainingHits > 0)
        {
            inserter--;
            if (inserter != _instrs.begin())
            {
                if (inserter->opcode == "#scu") { remainingHits--; }
                if (inserter->opcode == "#scd") { remainingHits++; }
                if (remainingHits == 0) { inserter++; break; }
            }

            if (!Utils::vectorContains(inserter->extraData, std::string("#raw")))
            {
                inserter->input1 = correctStackReference(inserter->input1, offset);
            }
            if (Utils::vectorContains(inserter->extraData, std::string("#pop")))
            {
                inserter->input2 = correctStackPop(inserter->input2, offset);
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

void MIPSContext::allocArray(Allocation allocation)
{
    _arrays.insert(allocation.name);
    
    if (isGlobalScope())
    {
        _globals.insert(allocation.name);
        _instrs.push_back(Instr(".data"));
        _instrs.push_back(Instr(".globl", allocation.name));
        _instrs.push_back(Instr(".size", allocation.name, std::to_string(allocation.size)));
        _instrs.push_back(Instr::makeLabel(allocation.name));
        _instrs.push_back(Instr(".space", std::to_string(allocation.size)));
    }
    else
    {
        Allocation arrAlloc = allocation;
        Allocation ptrAlloc = allocation;

        arrAlloc.name = "__" + arrAlloc.name + "__";
        ptrAlloc.size = 4;

        alloc(arrAlloc);
        alloc(ptrAlloc);

        loadAddress(ptrAlloc.name, arrAlloc.name);
    }
}

void MIPSContext::removeGlobalInits(std::string symbol)
{
    std::string foundSymbol;
    for (size_t i = 0; i < _instrs.size(); ++i)
    {
        if (_instrs[i].hasLabel()) { foundSymbol = _instrs[i].label; }
        if (foundSymbol == symbol)
        {
            if (_instrs[i].opcode == ".word" || _instrs[i].opcode == ".space")
            {
                _instrs.erase(_instrs.begin() + i);
                continue;
            }
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

std::string MIPSContext::correctStackPop(std::string popRef, int offset) const
{
    if (!std::regex_match(popRef, _isNumber)) { return popRef; }

    int originalSize = std::stoi(popRef);
    int correctedSize = originalSize - offset;
    return std::to_string(correctedSize);
}

void MIPSContext::addRootInstr(Instr instr)
{
    _instrs.insert(_instrs.begin(), instr);
}

void MIPSContext::addRawInstr(Instr instr)
{
    _instrs.push_back(instr);
}

void MIPSContext::addInstr(Instr instr, bool ignoreDest, bool ignoreInput1, bool ignoreInput2) { addInstr(instr, instr.label, ignoreDest, ignoreInput1, ignoreInput2); }
void MIPSContext::addInstr(Instr instr, std::string label, bool ignoreDest, bool ignoreInput1, bool ignoreInput2)
{
    std::string destName = instr.dest;
    if (destName == "_root") { return; }

    bool reqStore = !ignoreDest && requiresStack(instr.dest);
    if (reqStore) { allocIfRequired(instr.dest); }

    instr.label = label;
    instr.dest = reqStore ? "$t1" : destName;
    if (!ignoreInput1) { instr.input1 = loadInput(instr.input1, "$t2"); }
    if (!ignoreInput2) { instr.input2 = loadInput(instr.input2, "$t3"); }
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

    if (_globals.count(regName) > 0 && _arrays.count(regName) > 0)
    {
        _instrs.push_back(Instr("la", mipsReg, regName));
    }
    else
    {
        _instrs.push_back(Instr("lw", mipsReg, getAllocationLocation(regName)));
        _instrs.push_back(Instr("nop"));
    }
    
    return mipsReg;
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
        return regName;
    }
}

void MIPSContext::loadAddress(std::string destReg, std::string varName)
{
    if (_globals.count(varName) == 0)
    {
        allocIfRequired(destReg);
        int regLocation = _allocator.getAllocationOffset(varName);
        addInstr(Instr("addi", destReg, "$sp", std::to_string(regLocation), {"#pop"}), false, true, true);
    }
    else
    {
        addInstr(Instr("la", destReg, varName), false, true, true);
    }
}

void MIPSContext::allocIfRequired(std::string reg)
{
    if (requiresStack(reg))
    {
        if (!isAllocated(reg))
        {
            Allocation allocation(4, reg);
            alloc(allocation);
        }
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

const Allocator& MIPSContext::getAllocator() const
{
    return _allocator;
}

void MIPSContext::postProcessInstrs()
{
    for (size_t i = 0; i < _instrs.size(); ++i)
    {
        if (Utils::vectorContains(_instrs[i].extraData, std::string("#break")))
        {
            int deallocSize = 0;
            for (size_t j = i + 1; j < _instrs.size(); ++j)
            {
                if (_instrs[j].opcode == "addi" && _instrs[j].dest == "$sp" && _instrs[j].input1 == "$sp")
                {
                    if (!Utils::vectorContains(_instrs[j].extraData, std::string("#raw")))
                    {
                        deallocSize += std::stoi(_instrs[j].input2);
                    }
                }

                if (_instrs[j].label == _instrs[i].dest)
                {
                    Instr instr("addi", "$sp", "$sp", std::to_string(deallocSize), {"#raw"});
                    _instrs.insert(_instrs.begin() + i++, instr);
                    break;
                }
            }
        }

        if (Utils::vectorContains(_instrs[i].extraData, std::string("#continue")))
        {
            int allocSize = 0;
            for (int j = i - 1; j >= 0; --j)
            {
                if (_instrs[j].opcode == "addi" && _instrs[j].dest == "$sp" && _instrs[j].input1 == "$sp")
                {
                    if (!Utils::vectorContains(_instrs[j].extraData, std::string("#raw")))
                    {
                        allocSize -= std::stoi(_instrs[j].input2);
                    }
                }

                if (_instrs[j].label == _instrs[i].dest)
                {
                    Instr instr("addi", "$sp", "$sp", std::to_string(allocSize), {"#raw"});
                    _instrs.insert(_instrs.begin() + i++, instr);
                    break;
                }
            }
        }
    }
}