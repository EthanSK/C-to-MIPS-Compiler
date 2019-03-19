#include "sequenceBlock.hpp"

SequenceBlock::SequenceBlock() { }
SequenceBlock::SequenceBlock(StatementPtr branch) { branches.push_back(branch); }
SequenceBlock::SequenceBlock(std::vector<StatementPtr> branches){
    this->branches = branches;
}

void SequenceBlock::printC(std::ostream &os) const
{
    for(size_t i = 0; i < branches.size(); i++)
    {
        os << branches[i] << ";\n";
    }
    os << std::flush;
}

void SequenceBlock::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    for(size_t i = 0; i < branches.size(); i++)
    {
        context.indentStream(os, scopeDepth);
        branches[i]->generatePython(os, context, scopeDepth);
    }
    os << std::flush;
}