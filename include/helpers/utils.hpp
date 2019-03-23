#ifndef utils_hpp
#define utils_hpp

#include <string>

class Utils
{
public:
    static std::string padString(std::string str, int maxPadding, bool noComma = false);

    template <class DestType, class SrcType>
    static bool isType(const SrcType* src)
    {
        return dynamic_cast<const DestType*>(src) != nullptr;
    }

    template <class DestType, class SrcType>
    static const DestType* tryCast(const SrcType* src, std::string errorOnFail)
    {
        const DestType* dest= dynamic_cast<const DestType*>(src);
        if (dest) { return dest; }
        else { throw errorOnFail; }
    }
};

#endif