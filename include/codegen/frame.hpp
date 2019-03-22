#ifndef frame_hpp
#define frame_hpp

#include "allocation.hpp"
#include <vector>

class Frame
{
public:
    void allocate(Allocation allocation);
    int getAllocationOffset(std::string name) const;
    bool isAllocated(std::string name) const;

private:
    int _frameSize = 0;
    std::vector<Allocation> _allocations;
    std::vector<int> _allocationOffsets;

    int getAllocationPosition(std::string name) const;
};

#endif