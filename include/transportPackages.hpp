#ifndef transportPackages_hpp
#define transportPackages_hpp

#include "statement.hpp"
#include <string>

struct DeclPackage
{
    std::string identifier;
    StatementPtr init;
};

#endif