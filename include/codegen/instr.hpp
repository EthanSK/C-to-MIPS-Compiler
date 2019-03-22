#ifndef instr_hpp
#define instr_hpp

#include <vector>
#include <string>

struct Instr
{
    std::string label;                  //eg L1
    std::string opcode;                 //eg add
    std::string dest;                   //output register
    std::string input1;                 //input register
    std::string input2;                 //input register 2
    std::vector<std::string> extraData; //could be used for func params,

    //all properties w/out label
    Instr(std::string opcode, std::string dest, std::string input1, std::string input2, std::vector<std::string> extraData) : opcode(opcode), dest(dest), input1(input1), input2(input2), extraData(extraData){};

    //commonly used properties
    Instr(std::string opcode, std::string dest, std::string input1, std::string input2) : opcode(opcode), dest(dest), input1(input1), input2(input2){};

    //single input
    Instr(std::string opcode, std::string dest, std::string input1) : opcode(opcode), dest(dest), input1(input1){};

    //no implementation
    Instr(std::string opcode, std::string dest) : opcode(opcode), dest(dest){};

    //opcode
    Instr(std::string opcode) : opcode(opcode) {};

    Instr() { }

    static Instr makeLabel(std::string name)
    {
        Instr instr;
        instr.label = name;
        return instr;
    }

    bool hasLabel() const { return label != ""; }
};

#endif