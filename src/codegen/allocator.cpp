#include "allocator.hpp"

void Allocator::allocate(Allocation allocation)
{
    
}

void popFrame()
{
    _frames.pop_back();
}

void Allocator::pushFrame()
{
    _frames.push_back(AllocationFrame());
}

int Allocator::stackSize() const
{
    int size = 0;
    for (int i = 0; i < _frames.size(); ++i)
    {
        size += _frames[i].getFrameSize();
    }

    return size;
}

AllocationFrame& Allocator::topFrame()
{
    return _frames[_frames.size() - 1];
}