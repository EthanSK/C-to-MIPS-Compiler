#include <iomanip>
#include <map>

//for testing
#include "headers.hpp"
#include "instrPrinter.hpp"
#include "il2mips.hpp"

StatementPtr generateTestAST();
StatementPtr generateTestFragment();
extern FILE *yyin;
int main(int argc, char *argv[])
{
    try
    {
        bool isTranslatingToPython = false;
        bool isCompiling = true; //true for dev
        // Parse the AST
        yyin = fopen("test/parser/testProgram.c", "r"); //default value for dev

        if (argc >= 3 && std::string(argv[1]) == "-S")
        {
            isCompiling = true;
            yyin = fopen(argv[2], "r");
        }

        if (argc >= 5 && std::string(argv[1]) == "--translate")
        {
            isTranslatingToPython = true;
            yyin = fopen(argv[2], "r");
        }

        StatementPtr ast = parseAST();

        std::cerr << "\n\nC CODE\n======================\n";
        std::cerr << ast << std::endl;
        ast->writePrintCToFile();
        ast->writeDotFile();

        if (isTranslatingToPython)
        {
            std::cerr << "\n\nPYTHON CODE\n======================\n";
            ast->generatePython(std::cerr);
            ast->writePythonToFile(std::string(argv[4]));
            std::cerr << std::endl;
        }

        if (isCompiling)
        {
            std::cerr << "\n\nIL CODE\n======================\n";
            std::vector<Instr> instrs;
            ast->generateIL(std::cerr);
            ast->generateIL(instrs);
            ast->writeILToFile();

            std::cerr << "\n\nMIPS CODE\n======================\n";
            std::vector<Instr> Minstrs;
            Minstrs = IL2MIPS::convertToMIPS(instrs);
            //InstrPrinter::prettyPrintInstrs(std::cerr, Minstrs);
            InstrPrinter::generateInstrs(std::cout, Minstrs);
            InstrPrinter::writeMIPStoFile(std::string(argv[4]), Minstrs);
            InstrPrinter::writeMIPStoFile("bin/test.s", Minstrs);
        }

        std::cerr << std::endl;
        return 0;
    }
    catch (std::string str)
    {
        std::cerr << "ERROR\n======================\n";
        std::cerr << str << std::endl;
        std::exit(-1);
    }
    catch (const char *str)
    {
        std::cerr << "ERROR\n======================\n";
        std::cerr << str << std::endl;
        std::exit(-1);
    }
}
