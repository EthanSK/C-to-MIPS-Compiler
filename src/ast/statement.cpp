#include "statement.hpp"

std::ostream &operator<<(std::ostream &os, const Statement &statement)
{
    statement.printC(os);
    return os;
}

std::ostream &operator<<(std::ostream &os, const StatementPtr statementPtr)
{
    statementPtr->printC(os);
    return os;
}

void Statement::generatePython(std::ostream &os, PythonContext &context, int scopeDepth) const
{
    os << "[Not Supported: " << typeid(*this).name() << "]";
}

void Statement::generatePython(std::ostream &os) const
{
    PythonContext pyContext;
    generatePython(os, pyContext);
}

void Statement::printTree(std::ostream &os, int scopeDepth) const
{
    const int INDENT_SIZE = 2;
    for (int i = 0; i < scopeDepth * INDENT_SIZE; ++i)
    {
        os << " ";
    }
    os << "[" << typeid(*this).name() << "]";
    if (branches.size() > 0)
    {
        os << ":";
        for (int i = 0; i < branches.size(); ++i)
        {
            os << std::endl;
            branches[i]->printTree(os, scopeDepth + 1);
        }
    }
}

void Statement::generateTreeGraph(std::ostream &os, int scopeDepth) const
{
    for (int i = 0; i < branches.size(); i++)
    {
        os << "\"" << typeid(*this).name() << "\" -> ";
        branches[i]->generateTreeGraph(os, scopeDepth + 1);
        os << std::endl; 
    }




    // const int INDENT_SIZE = 2;
    // for (int i = 0; i < scopeDepth * INDENT_SIZE; ++i)
    // {
    //     os << " ";
    // }
    // os << "[" << typeid(*this).name() << "]";
    // if (branches.size() > 0)
    // {
    //     os << ":";
    //     for (int i = 0; i < branches.size(); ++i)
    //     {
    //         os << std::endl;
    //         branches[i]->generateTreeGraph(os, scopeDepth + 1);
    //     }
    // }
}

void Statement::writeDotFile(std::string filePath) const
{
    std::ofstream file(filePath, std::ios::out | std::ios::trunc);
    file << "digraph G { \n";
    this->generateTreeGraph(file);
    file << "\n}";
    file.close();
}

void Statement::writePrintCToFile(std::string filePath) const
{
    std::ofstream file(filePath, std::ios::out | std::ios::trunc);
    file << this;
    file.close();
}

void Statement::writePythonToFile(std::string filePath) const
{
    std::ofstream file(filePath, std::ios::out | std::ios::trunc);
    this->generatePython(file);
    file.close();
}

Statement::~Statement()
{
    for (size_t i = 0; i < branches.size(); i++)
    {
        delete branches[i];
    }
}