#include "utils.hpp"
#include <sstream>

std::string Utils::padString(std::string str, int maxPadding, bool noComma)
{
    std::stringstream ss;
    ss << str;
    if (str != "" && !noComma)
    {
        ss << ",";
    }
    for (int i = 0; i < maxPadding - str.size(); i++)
    {
        ss << " ";
    }
    return ss.str();
}