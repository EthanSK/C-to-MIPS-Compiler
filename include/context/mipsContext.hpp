#ifndef mipsContext_hpp
#define mipsContext_hpp

#include "context.hpp"
#include "allocator.hpp"
#include "instr.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <regex>

class MIPSContext : public Context 
{
public:
    std::vector<Instr> dumpInstrs() const;
    bool isGlobalScope() const;
    void pushFrame();
    void popFrame();
    void alloc(Allocation allocation);
    void allocArray(Allocation allocation);
    void addInstr(Instr instr, bool ignoreDest = false, bool ignoreInput1 = false, bool ignoreInput2 = false);
    void addInstr(Instr instr, std::string label, bool ignoreDest = false, bool ignoreInput1 = false, bool ignoreInput2 = false);
    void addBranchInstr(Instr instr);
    void addBranchInstr(Instr instr, std::string label);
    void addRootInstr(Instr instr);
    void addRawInstr(Instr instr);
    void loadAddress(std::string varName, std::string destReg);
    void postProcessInstrs();
    void removeGlobalInits(std::string symbol);
    int getAllocationSize(std::string regName) const;
    std::string getAllocationLocation(std::string regName) const;
    const Allocator& getAllocator() const;

private:
    Allocator _allocator;
    std::set<std::string> _globals;
    std::set<std::string> _arrays;
    std::vector<Instr> _instrs;
    std::regex _isNumber = std::regex("-?[0-9]+");
    std::regex _isStackRef = std::regex("-?[0-9]+\\(\\$sp\\)");

    bool requiresStack(std::string reg) const;
    bool isAllocated(std::string reg) const;
    void allocIfRequired(std::string reg);
    std::string loadInput(std::string regName, std::string mipsReg);
    std::string correctStackReference(std::string ref, int offset) const;
    std::string correctStackPop(std::string popRef, int offset) const;
};

#endif