#ifndef context_hpp
#define context_hpp

#include <iostream>

class Context
{
};

class PythonContext : public Context
{
public:
    void indentStream(std::ostream& os, int scopeDepth) const;

private:
    const int PY_INDENT_SIZE = 4;
};

#endif