#include "storageClass.hpp"

void StorageClass::printC(std::ostream &os) const
{
    os << storageClassSpecifierToString();
}

std::string StorageClass::storageClassSpecifierToString() const
{
    switch (_type)
    {
    case StorageClassSpecifierEnum::_typedef:
        return "typedef";
    case StorageClassSpecifierEnum::_extern:
        return "extern";
    case StorageClassSpecifierEnum::_static:
        return "static";
    case StorageClassSpecifierEnum::_auto:
        return "auto";
    case StorageClassSpecifierEnum::_register:
        return "register";
    default:
        return "UNKNOWN STORAGE CLASS";
    }
}