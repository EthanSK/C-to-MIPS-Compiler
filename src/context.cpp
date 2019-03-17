#include "context.hpp"

void PythonContext::indentStream(std::ostream& os, int scopeDepth) const
{
    os << std::endl;
    for (int i = 0; i < scopeDepth * PY_INDENT_SIZE; i++)
    {
        os << " ";
    }
}

void PythonContext::dumpGlobals(std::ostream& os, int scopeDepth) const
{
    for (int i = 0; i < _globalIdentifiers.size(); ++i)
    {
        indentStream(os, scopeDepth);
        os << "global " << _globalIdentifiers[i];
    }
}

void PythonContext::registerGlobal(std::string identifier)
{
    _globalIdentifiers.push_back(identifier);
}