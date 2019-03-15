#include "context.hpp"

void PythonContext::indentStream(std::ostream& os, int scopeDepth) const
{
    os << std::endl;
    for (int i = 0; i < scopeDepth * PY_INDENT_SIZE; i++)
    {
        os << " ";
    }
}