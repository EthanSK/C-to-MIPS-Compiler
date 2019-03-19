#include <iomanip>
#include <map>

//for testing
#include "headers.hpp"

StatementPtr generateTestAST();
StatementPtr generateTestFragment();
extern FILE *yyin;
int main(int argc, char *argv[])
{
    bool isTranslatingToPython = false;
    // Parse the AST
    yyin = fopen("test/parser/testProgram.c", "r"); //default value for dev

    if (argc >= 3 && std::string(argv[1]) == "-S")
    {
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

    std::cerr << std::endl;
    return 0;
}
