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