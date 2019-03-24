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
    void addInstr(Instr instr);
    void addInstr(Instr instr, std::string label);
    void addBranchInstr(Instr instr);
    void addBranchInstr(Instr instr, std::string label);
    void addRootInstr(Instr instr);
    void addRawInstr(Instr instr);
    int stackSize() const;
    std::string getAllocationLocation(std::string regName) const;

private:
    Allocator _allocator;
    std::set<std::string> _globals;
    std::vector<Instr> _instrs;
    std::regex _isNumber = std::regex("-?[0-9]+");
    std::regex _isStackRef = std::regex("-?[0-9]+\\(\\$sp\\)");

    bool requiresStack(std::string reg) const;
    bool isAllocated(std::string reg) const;
    std::string loadInput(std::string regName, std::string mipsReg);
    std::string correctStackReference(std::string ref, int offset) const;
};

#endif