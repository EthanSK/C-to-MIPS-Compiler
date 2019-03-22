#ifndef allocation_hpp
#define allocation_hpp

#include <string>

struct Allocation
{
    int size;
    std::string name;

    Allocation(int size, std::string name) : size(size), name(name) { }
};

#endif