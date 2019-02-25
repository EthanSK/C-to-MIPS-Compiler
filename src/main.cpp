#include "ast.hpp"
#include <iomanip>
#include <map>

int main(int argc, char *argv[])
{
    std::map<std::string, double> bindings;
    
    // Grab the pairs of bindings from argv
    for(int i=1; i<argc-1 ; i+=2){
        bindings.insert( std::make_pair( argv[i], strtod(argv[i+1],0) )  );
    }
    
    // Parse the AST
    StatementPtr ast = parseAST();
	ast->printCode(std::cout);

    return 0;
}
