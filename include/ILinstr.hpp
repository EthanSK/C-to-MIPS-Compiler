#ifndef ilinstr_hpp
#define ilinstr_hpp

#include <vector>
#include <string>

struct ILinstr
{
    std::string label;                  //eg L1
    std::string opcode;                 //eg add
    std::string dest;                   //output register
    std::string input1;                 //input register
    std::string input2;                 //input register 2
    std::vector<std::string> extraData; //could be used for func params,

    //all properties w/out label
    ILinstr(std::string opcode, std::string dest, std::string input1, std::string input2, std::vector<std::string> extraData) : opcode(opcode), dest(dest), input1(input1), input2(input2), extraData(extraData){};

    //commonly used properties
    ILinstr(std::string opcode, std::string dest, std::string input1, std::string input2) : opcode(opcode), dest(dest), input1(input1), input2(input2){};

    //single input
    ILinstr(std::string opcode, std::string dest, std::string input1) : opcode(opcode), dest(dest), input1(input1){};

    //no implementation
    ILinstr(std::string opcode, std::string dest) : opcode(opcode), dest(dest){};

    //label
    ILinstr(std::string label) : label(label) {};

    bool hasLabel() const { return label != ""; }
};

#endif