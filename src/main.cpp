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

    if (argc >= 5 && std::string(argv[1]) == "-S")
    {
         yyin = fopen(argv[2], "r");
    }

     if (argc >= 5 && std::string(argv[1]) == "--translate")
    {
        isTranslatingToPython = true;
        yyin = fopen(argv[2], "r");
    }

    StatementPtr ast = parseAST();

    std::cout << "\n\nC CODE\n======================\n";
    std::cout << ast << std::endl;
    ast->writePrintCToFile();


    if (isTranslatingToPython)
    {
        PythonContext context;
        std::cout << "\n\nPYTHON CODE\n======================\n";
        ast->generatePython(std::cout, context);
        ast->writePythonToFile(context, std::string(argv[4]));
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
