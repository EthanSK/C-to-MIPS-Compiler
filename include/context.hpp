#ifndef context_hpp
#define context_hpp

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <regex>
#include "allocator.hpp"
#include "instr.hpp"

class Context
{
};

class ILContext : public Context 
{
public:
    std::string makeName(std::string name);
    std::string makeLabelName(std::string name);

private:
    std::unordered_map<std::string, int> _registeredNames;
};

class MIPSContext : public Context 
{
public:
    std::vector<Instr> dumpInstrs() const;
    void pushFrame();
    void popFrame();
    void alloc(Allocation allocation);
    void addInstr(Instr instr);
    void addBranchInstr(Instr instr);
    void addRootInstr(Instr instr);
    void addRawInstr(Instr instr);
    int stackSize() const;
    std::string getAllocationLocation(std::string regName) const;

private:
    Allocator _allocator;
    std::set<std::string> _globals;
    std::vector<Instr> _instrs;
    std::regex _isNumber = std::regex("-?[0-9]+([.][0-9]+)?");

    bool requiresStack(std::string reg) const;
    bool isAllocated(std::string reg) const;
    std::string loadInput(std::string regName, std::string mipsReg);
};

class PythonContext : public Context
{
public:
    void indentStream(std::ostream& os, int scopeDepth) const;
    void registerGlobal(std::string identifier);
    void dumpGlobals(std::ostream& os, int scopeDepth) const;

private:
    std::vector<std::string> _globalIdentifiers;
    const int PY_INDENT_SIZE = 4;
};

#endif