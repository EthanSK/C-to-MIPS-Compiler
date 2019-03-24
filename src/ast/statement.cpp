#include "statement.hpp"
#include <sstream>
#include <algorithm>
#include "utils.hpp"
#include "instrPrinter.hpp"

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

std::string Statement::toString() const
{
    std::stringstream ss;
	ss << *this;
	return ss.str();
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

std::string Statement::getGraphNodeID() const
{
    const void *ptr = reinterpret_cast<const void *>(this);
    std::stringstream ss;
    ss << "ID" << ptr;
    return ss.str();
}

std::string Statement::getGraphNodeLabel() const
{
    std::stringstream ss;
    ss << "<";
    ss << typeid(*this).name();
    if (branches.size() == 0)
    {
        ss << "<font color='red'><b>";
    }
    if (branches.size() == 0)
    {
        ss << "<br/>"
           << *this;
    }
    if (branches.size() == 0)
    {
        ss << "</b></font>";
    }
    ss << ">";
    return ss.str();
}

void Statement::generateTreeGraph(std::ostream &os) const
{
    os << getGraphNodeID() << " [label=" << getGraphNodeLabel() << "]" << std::endl;
    for (int i = 0; i < branches.size(); ++i)
    {
        os << getGraphNodeID() << " -> " << branches[i]->getGraphNodeID() << ";" << std::endl;
        branches[i]->generateTreeGraph(os);
    }
}

void Statement::writeDotFile(std::string filePath) const
{
    std::ofstream file(filePath, std::ios::out | std::ios::trunc);
    file << "digraph AST { \n";
    generateTreeGraph(file);
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

void Statement::writeILToFile(std::string filePath) const
{
    std::ofstream file(filePath, std::ios::out | std::ios::trunc);
    this->generateIL(file);
    file.close();
}



void Statement::generateIL(std::vector<Instr> &instrs, ILContext &context, std::string destReg) const
{
    Instr instr("noImpl", typeid(*this).name());
    instrs.push_back(instr);
}

void Statement::generateIL(std::vector<Instr> &instrs) const
{
    ILContext context;
    generateIL(instrs, context, "_root");
}

void Statement::generateIL(std::ostream &os) const
{
    std::vector<Instr> instrs;
    generateIL(instrs);
    InstrPrinter::prettyPrintInstrs(os, instrs);
}

Statement::~Statement()
{
    for (size_t i = 0; i < branches.size(); i++)
    {
        delete branches[i];
    }
}
