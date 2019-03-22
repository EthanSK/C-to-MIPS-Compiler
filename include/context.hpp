#ifndef context_hpp
#define context_hpp

#include <iostream>
#include <vector>
#include <unordered_map>
#include "allocator.hpp"

class Context
{
};

class ILContext : public Context 
{
public:
    std::string makeName(std::string name);

private:
    std::unordered_map<std::string, int> _registeredNames;
};

class MIPSContext : public Context 
{
public:
    Allocator& getAllocator();

private:
    Allocator _allocator;
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