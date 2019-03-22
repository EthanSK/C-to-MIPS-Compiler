#include "allocationFrame.hpp"
#include <algorithm>

void AllocationFrame::allocate(Allocation allocation)
{
    _allocations.push_back(allocation);
    _allocationOffsets.push_back(_frameSize);
    _frameSize += allocation.size;
}

int AllocationFrame::getAllocationOffset(std::string name) const
{
    int pos = getAllocationPosition(name);
    if (pos < 0) { throw "allocation " + name + " could not be found"; }
    return _allocationOffsets[pos];
}

bool AllocationFrame::isAllocated(std::string name) const
{
    return getAllocationPosition(name) != -1;
}

int AllocationFrame::getFrameSize() const
{
    return _frameSize;
}

int AllocationFrame::getAllocationPosition(std::string name) const
{
    for (int i = 0; i < _allocations.size(); ++i)
    {
        if (name == _allocations[i].name) { return i; }
    }

    return -1;
}