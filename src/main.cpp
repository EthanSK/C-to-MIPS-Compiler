#include <iomanip>
#include <map>
#include "ast.hpp"

//for testing
#include "scopeBlock.hpp"
#include "functionDefinition.hpp"

int main(int argc, char *argv[])
{
    std::map<std::string, double> bindings;

    // Grab the pairs of bindings from argv
    for (int i = 1; i < argc - 1; i += 2)
    {
        bindings.insert(std::make_pair(argv[i], strtod(argv[i + 1], 0)));
    }

    // Parse the AST
    StatementPtr ast = parseAST();
    //ast->printC(std::cout);
    std::cout << ast << std::endl;
    return 0;
}

StatementPtr generateTestAST()
{
    // StatementPtr ast = new ScopeBlock();
    // StatementPtr test = new ScopeBlock();
    // std::vector<StatementPtr> vec;
    // // ast->branches.push_back(test); //doesn't work
    // vec.push_back(test);   
}
