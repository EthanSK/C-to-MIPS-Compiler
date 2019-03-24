#ifndef pythonContext_hpp
#define pythonContext_hpp

#include "context.hpp"
#include <iostream>
#include <vector>
#include <string>

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