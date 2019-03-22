#include "frame.hpp"
#include <algorithm>

void Frame::allocate(Allocation allocation)
{
    _allocations.push_back(allocation);
    _allocationOffsets.push_back(_frameSize);
    _frameSize += allocation.size;
}

int Frame::getAllocationOffset(std::string name) const
{
    int pos = getAllocationPosition(name);
    if (pos < 0) { throw "allocation " + name + " could not be found"; }
    return _allocationOffsets[pos];
}

bool Frame::isAllocated(std::string name) const
{
    return getAllocationPosition(name) != -1;
}

int Frame::getAllocationPosition(std::string name) const
{
    for (int i = 0; i < _allocations.size(); ++i)
    {
        if (name == _allocations[i].name) { return i; }
    }

    return -1;
}