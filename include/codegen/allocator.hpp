#ifndef allocator_hpp
#define allocator_hpp

#include "allocationFrame.hpp"
#include <vector>

class Allocator
{
public:
    void allocate(Allocation allocation);
    int getAllocationOffset(std::string name) const;
    bool isAllocated(std::string name) const;
    void popFrame();
    void pushFrame();
    int stackSize() const;

private:
    AllocationFrame& topFrame();
    std::vector<AllocationFrame> _frames;
};

#endif