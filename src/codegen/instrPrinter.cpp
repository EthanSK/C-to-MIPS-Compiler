#include "instrPrinter.hpp"
#include "utils.hpp"
#include <algorithm>

void InstrPrinter::printInstrs(std::ostream &os, std::vector<Instr> instrs)
{
    std::vector<unsigned long> columnWidths = {0, 0, 0, 0, 0};
    for (size_t i = 0; i < instrs.size(); i++)
    {
        columnWidths[0] = std::max(columnWidths[0], instrs[i].label.length());
        columnWidths[1] = std::max(columnWidths[1], instrs[i].opcode.length());
        columnWidths[2] = std::max(columnWidths[2], instrs[i].dest.length());
        columnWidths[3] = std::max(columnWidths[3], instrs[i].input1.length());
        columnWidths[4] = std::max(columnWidths[4], instrs[i].input2.length());
    }

    const int FIXED_PADDING = 4;
    for (int i = 0; i < columnWidths.size(); i++)
    {
        if (columnWidths[i] > 0)
        {
            columnWidths[i] += FIXED_PADDING;
        }
    }

    for (size_t i = 0; i < instrs.size(); i++)
    {
        std::string label = instrs[i].label;

        if (instrs[i].hasLabel())
        {
            label += ":";
        }
        std::string line;
        line += Utils::padString(label, columnWidths[0]);
        line += Utils::padString(instrs[i].opcode, columnWidths[1]);
        line += Utils::padString(instrs[i].dest, columnWidths[2]);
        line += Utils::padString(instrs[i].input1, columnWidths[3]);
        line += Utils::padString(instrs[i].input2, columnWidths[4]);
        os << line;

        for (size_t j = 0; j < instrs[i].extraData.size(); j++)
        {
            os << " " << instrs[i].extraData[j];
        }

        os << std::endl;
        if (instrs[i].opcode == "fend")
        {
            os << std::endl;
        }
    }
}

void InstrPrinter::generateInstrs(std::ostream &os, std::vector<Instr> instrs)
{
    for (size_t i = 0; i < instrs.size(); i++)
    {
        std::string label = instrs[i].label;

        if (instrs[i].hasLabel())
        {
            label.erase(std::remove(label.begin(), label.end(), '('), label.end());
            label.erase(std::remove(label.begin(), label.end(), ')'), label.end());
            label += ":";
        }
        std::string line;

        line += InstrPrinter::addCommaIfNeeded(label);
        line += InstrPrinter::addCommaIfNeeded(instrs[i].opcode);
        line += InstrPrinter::addCommaIfNeeded(instrs[i].dest);
        line += InstrPrinter::addCommaIfNeeded(instrs[i].input1);
        line += InstrPrinter::addCommaIfNeeded(instrs[i].input2);
        size_t last = line.find_last_of(',');
        if (std::string::npos != last)
        {
            line = line.substr(0, last);
        }
        os << line;

        for (size_t j = 0; j < instrs[i].extraData.size(); j++)
        {
            os << ", " << instrs[i].extraData[j]; //dunno when this would be present for mips instructions
        }

        os << std::endl;
    }
}

std::string InstrPrinter::addCommaIfNeeded(std::string &str)
{
    if (str != "")
    {
        str += ", ";
    }
    return str;
}

void InstrPrinter::writeMIPStoFile(std::string filePath, std::vector<Instr> instrs)
{
    std::ofstream file(filePath, std::ios::out | std::ios::trunc);
    InstrPrinter::generateInstrs(file, instrs);
    file.close();
}