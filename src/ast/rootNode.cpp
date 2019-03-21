#include "rootNode.hpp"

RootNode::RootNode(StatementPtr tree)
{
    branches.push_back(tree);
}

void RootNode::printC(std::ostream &os) const
{
    os << branches[0];
}

void RootNode::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    branches[0]->generatePython(os, context);
    os << std::endl
       << std::endl;

    os << "if __name__ == \"__main__\":";
    context.indentStream(os, 1);
    os << "import sys";
    context.indentStream(os, 1);
    os << "ret = main()";
    context.indentStream(os, 1);
    os << "sys.exit(ret)";
}

void RootNode::generateIL(std::vector<ILinstr> &instrs, ILContext &context, std::string destReg) const
{
    branches[0]->generateIL(instrs, context, destReg);
} 