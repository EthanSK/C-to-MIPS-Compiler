#ifndef ilinstr_hpp
#define ilinstr_hpp

#include <vector>
#include <string>


struct ILinstr
{
    std::string label; //eg L1
    std::string opcode; //eg add
    std::string dest;
    std::string in1;
    std::string in2;
    std::vector<std::string> extraData; //could be used for func params
};

#endif