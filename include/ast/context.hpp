#ifndef context_hpp
#define context_hpp

#include <iostream>
#include <vector>

class Context
{
};

class PythonContext : public Context
{
public:
    void indentStream(std::ostream& os, int scopeDepth) const;
    void registerGlobal(std::string identifier) { globalIdentifiers.push_back(identifier); }

private:
    std::vector<std::string> globalIdentifiers;
    const int PY_INDENT_SIZE = 4;
};

#endif