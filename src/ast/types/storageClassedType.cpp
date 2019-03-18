#include "storageClassedType.hpp"

StorageClassedType::StorageClassedType(StatementPtr child, StatementPtr storageClass)
{
    branches.push_back(child);
    branches.push_back(storageClass);
}

StatementPtr StorageClassedType::getChild() const
{
    return branches[0];
}

StatementPtr StorageClassedType::getStorageClass() const
{
    return branches[1];
}

void StorageClassedType::printC(std::ostream &os) const
{
    os << getStorageClass() << " " << getChild();
}