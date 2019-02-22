#include "ast.hpp"

#include <iomanip>

int main(int argc, char *argv[])
{
    std::map<std::string,double> bindings;
    
    // Grab the pairs of bindings from argv
    for(int i=1; i<argc-1 ; i+=2){
        bindings.insert( std::make_pair( argv[i], strtod(argv[i+1],0) )  );
    }
    
    // Parse the AST
    const Expression *ast=parseAST();
    
    // evaluate it with the bindings given
    double res=ast->evaluate(bindings);
    
    // Print it out
    std::cout << std::fixed << std::setprecision(6) << res << std::endl;

    return 0;
}
