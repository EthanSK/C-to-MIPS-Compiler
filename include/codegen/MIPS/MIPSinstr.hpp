#ifndef mipsinstr_hpp
#define mipsinstr_hpp

#include <vector>
#include <string>
#include "ILinstr.hpp"

struct MIPSinstr
{
    virtual std::string toString() const = 0;
};



#endif