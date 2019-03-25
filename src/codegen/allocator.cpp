#include "allocator.hpp"

void Allocator::allocate(Allocation allocation)
{
    _frames.back().allocate(allocation);
}

int Allocator::getAllocationOffset(std::string name) const
{
    for (int i = _frames.size() - 1; i >= 0; --i)
    {
        if (_frames[i].isAllocated(name))
        {
            int offset = _frames[i].getAllocationOffset(name);
            for (size_t j = i + 1; j < _frames.size(); ++j) { offset += _frames[j].getFrameSize(); }
            return offset;
        }
    }

    throw "allocation " + name + " could not be found";
}

bool Allocator::isAllocated(std::string name) const
{
    for (size_t i = 0; i < _frames.size(); ++i)
    {
        if (_frames[i].isAllocated(name)) { return true; }
    }

    return false;
}

void Allocator::popFrame()
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
    for (size_t i = 0; i < _frames.size(); ++i)
    {
        size += _frames[i].getFrameSize();
    }

    return size;
}

int Allocator::frameCount() const
{
    return _frames.size();
}

const AllocationFrame& Allocator::topFrame() const
{
    return _frames.back();
}