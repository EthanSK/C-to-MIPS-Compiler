#include "utils.hpp"
#include <sstream>

std::string Utils::padString(std::string str, int maxPadding)
{
    std::stringstream ss;
    ss << str;
    for (int i = 0; i < maxPadding - str.size(); i++) { ss << " "; }
    return ss.str();
}

