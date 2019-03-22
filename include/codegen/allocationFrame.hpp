#ifndef allocationFrame_hpp
#define allocationFrame_hpp

#include "allocation.hpp"
#include <vector>

class AllocationFrame
{
public:
    void allocate(Allocation allocation);
    int getAllocationOffset(std::string name) const;
    bool isAllocated(std::string name) const;
    int getFrameSize() const;

private:
    int _frameSize = 0;
    std::vector<Allocation> _allocations;
    std::vector<int> _allocationOffsets;

    int getAllocationPosition(std::string name) const;
};

#endif