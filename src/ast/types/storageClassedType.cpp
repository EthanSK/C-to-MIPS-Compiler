#include "storageClassedType.hpp"

StorageClassedType::StorageClassedType(StatementPtr child, StatementPtr storageClass)
{
    branches.push_back(child);
    branches.push_back(storageClass);
}

TypePtr StorageClassedType::getChild() const
{
   return reinterpret_cast<TypePtr>(branches[0]);
}

StatementPtr StorageClassedType::getStorageClass() const
{
    return branches[1];
}

void StorageClassedType::printC(std::ostream &os) const
{
    os << getStorageClass() << " " << getChild();
}

int StorageClassedType::getTypeSize() const { return getChild()->getTypeSize(); }